cmake_minimum_required(VERSION 3.10)

project(IntSetProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(IntSetProject
    main.cpp
    IntSet.cpp
)
