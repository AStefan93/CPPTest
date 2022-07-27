# Dockerfile contents:
FROM ubuntu:latest
ENV DEBIAN_FRONTEND="noninteractive" TZ="America/Toronto"

ARG USERNAME=vscode
ARG USER_UID=1000
ARG USER_GID=$USER_UID

# Create the user
RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    #
    # [Optional] Add sudo support. Omit if you don't need to install software after connecting.
    && apt-get update \
    && apt-get install -y sudo \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

# ********************************************************
# * Anything else you want to do like clean up goes here *
# ********************************************************
RUN apt-get update && apt-get -y install build-essential cppcheck valgrind clang clangd clang-tidy clang-format lldb llvm gdb git vim\
    && apt-get -y install nodejs npm \
    && npm install -g @bazel/bazelisk \
    && apt-get -y install protobuf-compiler \
    && apt-get -y install wget \
    && apt-get -y install python3 \
    && apt-get -y install default-jdk

# Install latest git version
RUN apt-get install software-properties-common -y && apt-add-repository ppa:git-core/ppa && apt-get update && apt-get install git -y

#Install Buildifier and add to path
RUN wget -O /usr/bin/buildifier https://github.com/bazelbuild/buildtools/releases/download/5.0.1/buildifier-linux-amd64 \
    && chmod +x /usr/bin/buildifier

RUN apt-get autoremove -y && apt-get clean -y && rm -rf /var/lib/apt/lists/*

#Fix bazel compile commands generation extension
WORKDIR /workspaces/CPPTest
RUN ln -s bazel-out/../../../external
RUN chown -R $USERNAME /workspaces/CPPTest

# [Optional] Set the default user. Omit if you want to keep the default as root.
USER $USERNAME