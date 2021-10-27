#!/bin/sh
set -e

PROJECTS_TO_BUILD=$@
if [ -d ./build ]; then
    echo "Directory build/ exists, will remove."
    rm -rf ./build
fi

CMAKE_OPTIONS=""
for PROJECT in $PROJECTS_TO_BUILD
do
    echo "Adding ${PROJECT} to build tree."
    CMAKE_OPTIONS="${CMAKE_OPTIONS}-DBUILD_${PROJECT}=ON "
done

cmake $CMAKE_OPTIONS . -B ./build
cmake --build ./build
