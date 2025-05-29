FROM ubuntu:22.04


ENV DEBIAN_FRONTEND=noninteractive

# Install dependencies
RUN apt-get update && \
    apt-get install -y g++ cmake make build-essential && \
    apt-get clean && rm -rf /var/lib/apt/lists/*


WORKDIR /bb84


COPY . .


RUN cmake -S . -B build && cmake --build build


CMD ["./build/bb84_simulation"]
