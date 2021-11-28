#!/bin/bash

function print_usage {
    echo -e """Usage:
\tbuild_image.sh <alpine|ubuntu>

alpine - create this image with alpine linux as the base image
ubuntu - create this image with ubuntu linux as the base image
"""
}

if [[ ${1} == "alpine" ]]; then
    docker build -f Dockerfile-alpine --tag alpine-build-machine:latest .
elif [[ ${1} == "ubuntu" ]]; then
    docker build -f Dockerfile --tag ubuntu-build-machine:latest .
else
    print_usage
fi
