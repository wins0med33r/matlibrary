enable_testing()

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB_RECURSE TEST_SOURCES */*.cpp)
message("Test sources: ${TEST_SOURCES}")

add_executable(matlibrary_tests ${TEST_SOURCES})

target_link_libraries(matlibrary_tests PRIVATE matlibrary)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)
if(Boost_FOUND)
	target_link_libraries(matlibrary_tests PRIVATE Boost::unit_test_framework)
else()
	message("Can't find Boost library m8")
endif()

add_test(NAME MatLibraryTests COMMAND matlibrary_tests)