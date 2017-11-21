cmake_minimum_required(VERSION 3.8)
project(Assignment_5)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BST.cpp BST.h QueueL.cpp QueueL.h Stackt.cpp Stackt.h Dictionary.cpp Dictionary.h)
add_executable(Assignment_5 ${SOURCE_FILES})