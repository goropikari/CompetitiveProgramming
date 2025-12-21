# https://img.atcoder.jp/file/language-update/2025-10/language-list.html
FROM gcc:15.2.0-trixie

ENV CPLUS_INCLUDE_PATH=/opt/ac-library

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y \
        # pipx \
        git \
        curl \
        time \
        ripgrep \
        fd-find \
        direnv \
        libreadline-dev \
        libboost-math-dev && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

RUN mkdir -p /opt && \
    git clone -b v1.6 --depth 1 https://github.com/atcoder/ac-library /opt/ac-library && \
    cd /usr/include/x86_64-linux-gnu/c++/14/bits && \
    g++ --std=c++23 stdc++.h

RUN useradd -m -s /bin/bash vscode
WORKDIR /home/vscode
RUN mkdir -p /home/vscode/.local/share
RUN mkdir -p /home/vscode/.config
RUN chown -R vscode:vscode /home/vscode
RUN chown -R vscode:vscode /home/vscode/.local
RUN chown -R vscode:vscode /home/vscode/.config

USER vscode
