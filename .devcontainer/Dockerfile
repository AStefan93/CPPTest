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
RUN apt-get update && apt-get -y install apt-utils build-essential cppcheck valgrind clangd gdb git vim\
    && apt-get -y install nodejs npm \
    && apt-get -y install protobuf-compiler \
    && apt-get -y install wget \
    && apt-get -y install python3 \
    && apt-get -y install python3-pip \
    && apt-get -y install default-jdk \
    && apt-get -y install lcov \
    #
    # Install python packages
    && pip3 install conan \
    #    
    # Install latest git version
    && apt-get install software-properties-common -y && apt-add-repository ppa:git-core/ppa && apt-get update && apt-get install git -y \
    #
    # Install latest cmake
    && wget https://github.com/Kitware/CMake/releases/download/v3.28.0/cmake-3.28.0-Linux-x86_64.sh -q -O /tmp/cmake-install.sh \
    && chmod u+x /tmp/cmake-install.sh \
    && sudo mkdir /opt/cmake-3.28.0 \
    && sudo /tmp/cmake-install.sh --skip-license --prefix=/opt/cmake-3.28.0 \
    && rm /tmp/cmake-install.sh \
    && sudo ln -s /opt/cmake-3.28.0/bin/* /usr/local/bin

# Install latest llvm
COPY install_llvm.sh .
RUN install_llvm.sh

 # Clean up
RUN apt-get autoremove -y && apt-get clean -y && rm -rf /var/lib/apt/lists/*