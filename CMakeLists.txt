cmake_minimum_required(VERSION 3.8)
project(Assignment_5)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Dictionary.cpp Dictionary.h BST.cpp BST.h)
add_executable(Assignment_5 ${SOURCE_FILES} BST.cpp BST.h)