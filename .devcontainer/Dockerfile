FROM ubuntu:22.04

# Install required packages
RUN apt-get update && apt-get install -y \
    g++ cmake make git build-essential \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /workspace
