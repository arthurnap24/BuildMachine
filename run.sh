#!/bin/bash
set -e

OS=$1
if [[ $OS == "alpine" ]]; then
    SHELL="/bin/ash"
elif [[ $OS == "ubuntu" ]]; then
    SHELL="/bin/bash"
else
    echo "Usage:"
    echo -e "\trun.sh <alpine|ubuntu>"
    echo "alpine - create this image with alpine linux as the base image"
    echo "ubuntu - create this image with ubuntu linux as the base image"
    exit 0
fi

docker compose pull
SERVICE="${OS}-build-machine"
docker compose run --rm $SERVICE $SHELL