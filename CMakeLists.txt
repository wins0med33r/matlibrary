cmake_minimum_required (VERSION 3.8)

project ("matlibrary")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_library(matlibrary STATIC
    src/Matrix.cpp
)

add_executable(run_main
    matrix/main.cpp
)
