cmake_minimum_required(VERSION 3.12)
project(UseOpenSSL)

set(CMAKE_CXX_STANDARD 14)

INCLUDE_DIRECTORIES(include)

LINK_DIRECTORIES(libs/mac) # or libs/linux

LINK_LIBRARIES(ssl crypto)

SET(SRC main.cpp hash.cpp hash.h base64.cpp base64.h)

ADD_EXECUTABLE(UseOpenSSL ${SRC})