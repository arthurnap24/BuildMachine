## BuildMachine

My personal development container that I can use for C++ developments on Ubuntu Linux.

The relevant Docker images used by docker compose in this project are:
- [arthurnap24/alpine-build-machine](https://hub.docker.com/r/arthurnap24/alpine-build-machine)
- [arthurnap24/ubuntu-build-machine](https://hub.docker.com/r/arthurnap24/ubuntu-build-machine)

### How To Run Container
You need to specify the directory that the build environment would use in the `.env` file (example in this repo is .env.dev). This will contain the source code you're working with or perhaps another repository.

In `.env` file add:
`APP_FOLDER=<a valid directory in your filesystem>`

then execute:
`./run.sh <alpine|ubuntu>`

### How To Build Example Projects
In the host machine, open a terminal and run these commands (check the [Examples](https://github.com/arthurnap24/Examples.git) for more details):
```
cd ~
git clone https://github.com/arthurnap24/Examples.git
# Or directory where you have this repo
cd ./BuildMachine
echo "APP_FOLDER=~/Examples" > .env

# Run the container
./run.sh ubuntu

# Inside the container -- builds all sample projects
./build.sh
```

The `build.sh` script invokes the `cmake --build` command after generating the build files. To provide options to `cmake --build`, just pass them to this script as you would to `cmake --build`.

Example:
- Clean first: `./build.sh --clean-first`
- Clean first and build two sample projects: `./build.sh --clean-first -t <project1> -t <project2>`

### How To Build Image
Execute:
```
cd ci && ./build_image.sh
```

### How To Push Image to your own repo

Run:
```
export DOCKER_USER=<your Docker account's username>
export DOCKER_PASSWORD=<your Docker account's password>
./push_image.sh all
```

See script's help string.

### Packages downloaded in Image
These packages are downloaded via APK (alpine-build-image) or APT (ubuntu-build-image):
- CMake
- GTest
- Asio
