FROM mcr.microsoft.com/devcontainers/base:ubuntu-24.04

RUN apt-get update && apt-get upgrade -y && \
    apt-get install -y \
      python3 \
      python3-venv \
      build-essential \
      unzip \
      direnv \
      time \
      ripgrep

RUN wget https://github.com/gohugoio/hugo/releases/download/v0.140.0/hugo_0.140.0_linux-amd64.deb && \
    dpkg -i hugo_0.140.0_linux-amd64.deb
