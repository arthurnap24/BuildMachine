## CppUbuntu

My personal development container that I can use for C++ developments on Ubuntu Linux.

The Docker image used by this container can be found here:
[arthurnap24/cpp-build-machine](https://hub.docker.com/r/arthurnap24/cpp-build-machine)

### How To Run Container
You need to specify the directory that the build environment would use in the `.env` file (example in this repo is .env.dev). This will contain the source code you're working with or perhaps another repository.

In `.env` file add:
`APP_FOLDER=<a valid directory in your filesystem>`

then execute:
`./run.sh`

### How To Build Example Projects
Run the container - When you get to the container's shell, execute the command below.

To build all sample projects:
`./build.sh`

This script invokes the `cmake --build` command after generating the build files. To provide options to `cmake --build`, just pass them to this script as you would to `cmake --build`.

Example:
- Clean first: `./build.sh --clean-first`
- Clean first and build two sample projects: `./build.sh --clean-first -t <project1> -t <project2>`

### How To Build Image
Execute:
`cd ci && ./build_image.sh`

### Packages downloaded in Image
These packages are downloaded via APT:
- CMake
- GTest
