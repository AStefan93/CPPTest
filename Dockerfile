# Dockerfile contents:
FROM ubuntu:20.04
ENV DEBIAN_FRONTEND="noninteractive" TZ="America/Toronto"
RUN apt-get update
RUN apt-get upgrade
