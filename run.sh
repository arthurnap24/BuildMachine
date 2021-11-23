#!/bin/bash
set -e

if [[ $1 == "alpine" ]]; then
    docker compose run --rm cpp-dev-machine /bin/ash
elif [[ $1 == "ubuntu" ]]; then
    docker compose run --rm cpp-dev-machine /bin/bash
else
    echo "TODO: Add better way of doing this"
fi
