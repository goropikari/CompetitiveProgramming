# https://mcr.microsoft.com/en-us/artifact/mar/devcontainers/cpp/tags
FROM mcr.microsoft.com/devcontainers/cpp:ubuntu-24.04

ENV CPLUS_INCLUDE_PATH=/opt/ac-library

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y \
        curl \
        time \
        ripgrep \
        fd-find \
        libreadline-dev
