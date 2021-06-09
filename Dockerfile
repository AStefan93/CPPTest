# Dockerfile contents:
FROM ubuntu:latest
ENV DEBIAN_FRONTEND="noninteractive" TZ="America/Toronto"
RUN apt-get update && apt-get -y install build-essential cmake cppcheck valgrind clang lldb llvm gdb git \
    && apt-get -y install nodejs npm \
    && npm install -g @bazel/bazelisk
    
RUN apt-get autoremove -y && apt-get clean -y && rm -rf /var/lib/apt/lists/*