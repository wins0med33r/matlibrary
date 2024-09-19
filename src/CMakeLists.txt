include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SRC_SOURCES */*.cpp)
message(STATUS "src source files: ${SRC_SOURCES}")

add_library(matlibrary STATIC ${SRC_SOURCES})
