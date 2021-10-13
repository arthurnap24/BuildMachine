#!/bin/bash

function print_usage {
  echo "Invalid usage:"
  echo "	./run.sh <cpp-dev-machine|cpp-dev-machine-test>"
}

if [ -z "$1" ]; then
  print_usage
  exit 0
fi

SERVICE=$1
docker compose run --rm $SERVICE /bin/bash
