#!/bin/bash

if [[ ${1} == "alpine" ]]; then
    docker build -f Dockerfile-alpine --tag alpine-build-machine:latest .
elif [[ ${1} == "ubuntu" ]]; then
    docker build -f Dockerfile --tag ubuntu-build-machine:latest .
else
    echo "Usage:"
    echo -e "\tbuild_image.sh <alpine|ubuntu>"
    echo "alpine - create this image with alpine linux as the base image"
    echo "ubuntu - create this image with ubuntu linux as the base image"
fi
