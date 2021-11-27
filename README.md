# continuous_mutation_docker

## Building the docker image

1. Clone the repo and extract the archives
```
git clone https://github.com/thierry-tct/continuous_mutation_docker
cd continuous_mutation_docker
```

2. Create image by running:
```
docker build -t thierrytct/cm .
```

3. upload image by running (after `docker login`):
```
docker push thierrytct/cm
```

## Usage example

executing the muteria [example_c](https://github.com/muteria/example_c)

```
docker run -it --rm thierrytct/cm "cd /home/cmtools/example_c && muteria --config ctrl/conf_shadow_semu.py --lang c run"
```
