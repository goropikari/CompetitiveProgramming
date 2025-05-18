# https://mcr.microsoft.com/en-us/artifact/mar/devcontainers/cpp/tags
FROM mcr.microsoft.com/devcontainers/cpp:ubuntu-24.04

ENV CPLUS_INCLUDE_PATH=/opt/ac-library

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y \
        git \
        curl \
        time \
        ripgrep \
        fd-find \
        libreadline-dev \
        gcc-12 \
        libboost-math-dev

RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-12 20

RUN mkdir -p /opt && \
    git clone -b v1.5.1 --depth 1 https://github.com/atcoder/ac-library /opt/ac-library && \
    cd /usr/include/x86_64-linux-gnu/c++/13/bits && \
    g++ --std=c++23 stdc++.h
