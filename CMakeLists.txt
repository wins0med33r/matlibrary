cmake_minimum_required (VERSION 3.8)

project ("matlibrary")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR}/include/)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

message(${matlibrary_SOURCE_DIR})
add_library(matlibrary STATIC
	${matlibrary_SOURCE_DIR}/include/Matrix.cpp
	${matlibrary_SOURCE_DIR}/include/Matrix.hpp
)

add_subdirectory(Tests)
