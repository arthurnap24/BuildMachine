#!/bin/bash

function print_usage {
  echo "Invalid usage:"
  echo "	./run_dev_container.sh <tests|projects>"
}

if [ -z "$1" ]; then
  print_usage
  exit 0
fi

if [ $1 = "tests" ]; then
  docker run -v ~/CppUbuntu/tests:/usr/src/myapp -it cpp-build-machine /bin/bash
elif [ $1 = "projects" ]; then
  docker run -v ~/CppUbuntu/projects:/usr/src/myapp -it cpp-build-machine /bin/bash
else
  print_usage
fi
