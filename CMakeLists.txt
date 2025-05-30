cmake_minimum_required(VERSION 3.10)
project(BB84Implementation)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SOURCES "src/*.cpp")


add_executable(bb84_simulation ${SOURCES})
