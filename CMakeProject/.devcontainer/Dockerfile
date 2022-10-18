# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.245.0/containers/cpp/.devcontainer/base.Dockerfile

# [Choice] Debian / Ubuntu version (use Debian 11, Ubuntu 18.04/22.04 on local arm64/Apple Silicon): debian-11, debian-10, ubuntu-22.04, ubuntu-20.04, ubuntu-18.04
ARG VARIANT="ubuntu-22.04"
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}

# ********************************************************
# * Anything else you want to do like clean up goes here *
# ********************************************************
RUN apt-get update && apt-get -y install build-essential cppcheck valgrind clang clangd clang-tidy clang-format lldb llvm gdb git vim\
 && apt-get -y install nodejs npm \
 && apt-get -y install wget \
 && apt-get -y install python3 \
 && apt-get -y install python3-pip \
 && apt-get -y install default-jdk \
 && apt-get -y install lcov

RUN pip install cmake_format \
&&  pip install conan

# Install JFrog
RUN curl -fL "https://install-cli.jfrog.io" | sh; jf setup eyJ1cmwiOiJodHRwczovL2NwcHRlc3QuamZyb2cuaW8vIiwidXNlciI6ImFybmF1dHUuc3RlZmFuOTNAZ21haWwuY29tIiwicGFzc3dvcmQiOiJBS0NwOG5GdnNIa0dIQ3hyMTY5YnZGZzVhZEZ1cWVCb1FnV1dFQXE5eFdhN3hURDFXYjNoNVEzUnh0RnhGNGNHMkp6MzVkaFc5In0=

# Clean
RUN apt-get autoremove -y && apt-get clean -y && rm -rf /var/lib/apt/lists/*
