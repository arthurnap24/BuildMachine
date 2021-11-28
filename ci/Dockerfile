FROM gcc:latest
WORKDIR /usr/src/myapp

RUN apt update \
    && apt upgrade \
    && apt -y install cmake \
    && apt -y install libasio-dev \
    && apt -y install libgtest-dev \
    && apt -y install libgmock-dev \
    && cd /usr/src/googletest/googletest \
    && mkdir build \
    && cd build \
    && cmake .. \
    && make \
    && cp ./lib/libgtest* /usr/lib/ \
    && cd .. \
    && rm -rf build \
    && mkdir /usr/local/lib/googletest \
    && ln -s /usr/lib/libgtest.a /usr/local/lib/googletest/libgtest.a \
    && ln -s /usr/lib/libgtest_main.a /usr/local/lib/googletest/libgtest_main.a \
