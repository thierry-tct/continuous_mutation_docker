# sudo docker build --no-cache -t thierrytct/cm . && sudo docker push thierrytct/cm

ARG semu_llvm_version=3.4.2

FROM thierrytct/klee-semu:llvm-$semu_llvm_version

RUN apt-get update && apt-get -y install git gdb vim sudo && echo '%sudo ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers

ARG shadow_location=/home/shadowvm/shadow

# Install Muteria and Copy Shadow
RUN pip3 install --upgrade pip \
  && pip install -U muteria && mkdir -p $shadow_location

COPY shadow $shadow_location/

# shadow env
ENV C_INCLUDE_PATH /usr/include/x86_64-linux-gnu
ENV CPLUS_INCLUDE_PATH /usr/include/x86_64-linux-gnu
ENV LIBRARY_PATH $LIBRARY_PATH:/usr/lib/x86_64-linux-gnu:/usr/lib64
ENV LD_LIBRARY_PATH $LD_LIBRARY_PATH:/usr/lib/x86_64-linux-gnu:/usr/lib64
ENV LLVM_LIB_SEARCH_PATH $LLVM_LIB_SEARCH_PATH:/usr/lib/x86_64-linux-gnu:/usr/lib64

# create a non root user
RUN adduser --home /home/cmtools --uid 8878 --disabled-login --disabled-password cmtools && adduser cmtools sudo \
  && git clone https://github.com/muteria/example_c.git /home/cmtools/example_c

COPY run.sh /home/cmtools
USER cmtools

# upgrade muteria if new version and ulimit for shadow
#ENTRYPOINT ulimit -s unlimited && sudo pip install muteria -U
#ENTRYPOINT ulimit -s unlimited


CMD echo "HELLO CM"


# Run Docker as following:
#> sudo docker run -it --rm --cap-add=SYS_PTRACE --security-opt seccomp=unconfined --mount type=bind,src=$(pwd),dst=/work --user 1000:1000 --privileged  thierrytct/cm  bash
