#!/bin/bash

main() {
    if [[ $1 == "-h" ]]; then
        print_usage
        exit 0
    fi
    OS=$1
    docker_authenticate
    docker_push $OS
}

docker_authenticate() {
    check_has_auth_env_vars
    login
}

check_has_auth_env_vars() {
    if [ -z $DOCKER_USER ] || [ -z $DOCKER_PASSWORD ]; then
        print_usage
        exit 0;
    fi
}

login() {
    docker login --username $DOCKER_USER --password $DOCKER_PASSWORD
}

docker_push() {
    OS=$1
    if [[ $OS == "alpine" ]]; then
        push_image_alpine
    elif [[ $OS == "ubuntu" ]]; then
        push_image_ubuntu
    elif [[ $OS == "all" ]]; then
        push_all_supported_images
    else
        os_not_supported_error
    fi    
}

push_image_alpine() {
    push_image "alpine"
}

push_image_ubuntu() {
    push_image "ubuntu"
}

push_all_supported_images() {
    push_image_alpine
    push_image_ubuntu
}

push_image() {
    OS=$1
    IMAGE="${OS}-build-machine:latest"
    IMAGE_TAG="${DOCKER_USER}/${IMAGE}"
    docker tag $IMAGE $IMAGE_TAG
    docker push $IMAGE_TAG
}

os_not_supported_error() {
    print_not_supported
    exit 1;
}

print_not_supported() {
    echo """
The operating system is not supported, please run with -h flag to view all supported OS.
"""
}

print_usage() {
    echo -e """Usage:
\tpush_image.sh <operating-system>

Supported operating-system values:
alpine - tags the local alpine-build-machine:latest
ubuntu - tags the local ubuntu-build-machine:latest with \$DOCKER_USER environment variable
all - tags all listed supported images with \$DOCKER_USER environment variable

The Docker commands in this script requires these environment variables:
DOCKER_USER=<your Docker account's username>
DOCKER_PASSWORD=<your Docker account's password>
"""
}

main $@
