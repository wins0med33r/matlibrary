cmake_minimum_required(VERSION 3.8)

enable_testing()

include_directories(${CMAKE_SOURCE_DIR}/include)

if(MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")  # Use /MDd for dynamic
endif()

file(GLOB_RECURSE TEST_SOURCES */*.cpp)
message("Test sources: ${TEST_SOURCES}")

add_executable(matlibrary_tests ${TEST_SOURCES})

add_subdirectory(C:\\Users\\patri\\Code\\googletest ${CMAKE_BINARY_DIR}/googletest-build)

target_link_libraries(matlibrary_tests PRIVATE matlibrary gtest gtest_main)

add_test(NAME MatLibraryTests COMMAND matlibrary_tests)