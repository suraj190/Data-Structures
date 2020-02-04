cmake_minimum_required(VERSION 3.9)
project(ExtraCredit___MyVector)

set(CMAKE_CXX_STANDARD 14)
set(GXX_ENABLE_WARNINGS "-O1 -Wall -Werror -Wno-unused-result")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GXX_ENABLE_WARNINGS}")


add_executable(ExtraCredit___MyVector main.cpp MyVector.h ConstVectorItr.h VectorItr.h)