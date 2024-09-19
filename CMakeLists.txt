cmake_minimum_required (VERSION 3.8)

project ("matlibrary")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_subdirectory(src)
add_subdirectory(Tests)
