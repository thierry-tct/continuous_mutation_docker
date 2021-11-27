# continuous_mutation_docker

Clone the repo and extract the archives
```
git clone https://github.com/thierry-tct/continuous_mutation_docker
cd continuous_mutation_docker
cd shadow/kleeDeploy && tar -xzf llvm-2.9.tgz && tar -xf llvm-gcc4.2-2.9-x86_64-linux.tar.bz2 && cd -
```

Create image by running:
```
docker build -t thierrytct/cm .
```

upload image by running (after `docker login`):
```
docker push thierrytct/cm
```
