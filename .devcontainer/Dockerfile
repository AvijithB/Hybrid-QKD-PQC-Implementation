FROM ubuntu:22.04

# Install required packages
RUN apt-get update && apt-get install -y \
    python3 python3-pip \
    g++ cmake make git build-essential \
    && rm -rf /var/lib/apt/lists/*

COPY ../requirements.txt /tmp/requirements.txt
RUN pip3 install --no-cache-dir -r /tmp/requirements.txt
RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install gh -y

# Set working directory
WORKDIR /workspace
