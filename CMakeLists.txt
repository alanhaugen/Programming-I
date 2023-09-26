cmake_minimum_required(VERSION 3.5)

project(app LANGUAGES CXX)

add_executable(app source/main.cpp source/inputfunctions.cpp source/polynomial.cpp source/principia.cpp)
