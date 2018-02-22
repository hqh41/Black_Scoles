cmake_minimum_required(VERSION 3.8)
project(projet)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp call.cpp call.h payoff.cpp payoff.h matrix.cpp matrix.h put.cpp put.h)
add_executable(projet ${SOURCE_FILES})