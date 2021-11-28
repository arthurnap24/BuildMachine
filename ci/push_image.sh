#!/bin/bash

function print_usage {
    echo -e """Usage:
\tpush_image.sh [alpine|ubuntu|all]

You need to have this environment variables:
DOCKER_USER=<your Docker account's username>
DOCKER_PASSWORD=<your Docker account's password>

alpine - tags the local alpine-build-machine:latest with \$DOCKER_USER environment variable
ubuntu - tags the local ubuntu-build-machine:latest with \$DOCKER_USER environment variable
all - tags both alpine and ubuntu images with \$DOCKER_USER environment variable
"""
}

if [ -z $DOCKER_USER ] || [ -z $DOCKER_PASSWORD ]; then
    print_usage
    exit 0;
fi

ALPINE_IMAGE="alpine-build-machine:latest"
UBUNTU_IMAGE="ubuntu-build-machine:latest"
ALPINE_IMAGE_TAG="${DOCKER_USER}/alpine-build-machine:latest"
UBUNTU_IMAGE_TAG="${DOCKER_USER}/ubuntu-build-machine:latest"

if [ -z $1 ]; then
    print_usage
    exit 0;
fi

docker login --username $DOCKER_USER --password $DOCKER_PASSWORD

if [[ $1 == "alpine" ]]; then
    docker tag $ALPINE_IMAGE $ALPINE_IMAGE_TAG
    docker push $ALPINE_IMAGE_TAG
elif [[ $1 == "ubuntu" ]]; then
    docker tag $UBUNTU_IMAGE $UBUNTU_IMAGE_TAG
    docker push $UBUNTU_IMAGE_TAG
elif [[ $1 == "all" ]]; then
    docker tag $ALPINE_IMAGE $ALPINE_IMAGE_TAG
    docker tag $UBUNTU_IMAGE $UBUNTU_IMAGE_TAG
    docker push $ALPINE_IMAGE_TAG
    docker push $UBUNTU_IMAGE_TAG
fi