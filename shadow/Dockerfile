ARG mart_llvm_version=3.4.2
ARG shadow_location=/home/shadowvm/shadow

FROM thierrytct/mart:llvm$mart_llvm_version

# Install Muteria and Copy Shadow
RUN pip install muteria && mkdir -p $shadow_location && cp -r ./shadow/* $shadow_location/

# shadow env
ENV C_INCLUDE_PATH /usr/include/x86_64-linux-gnu
ENV CPLUS_INCLUDE_PATH /usr/include/x86_64-linux-gnu
ENV LIBRARY_PATH $LIBRARY_PATH:/usr/lib/x86_64-linux-gnu:/usr/lib64
ENV LD_LIBRARY_PATH $LD_LIBRARY_PATH:/usr/lib/x86_64-linux-gnu:/usr/lib64
ENV LLVM_LIB_SEARCH_PATH $LLVM_LIB_SEARCH_PATH:/usr/lib/x86_64-linux-gnu:/usr/lib64

# upgrade muteria if new version and ulimit for shadow
ENTRYPOINT ulimit -s unlimited && pip install muteria -U
