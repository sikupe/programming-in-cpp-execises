cmake_minimum_required(VERSION 3.22)
project(integer_matrix)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(matrix_test matrix_test.cpp IntegerMatrix.hpp IntegerMatrix.cpp)

target_link_libraries(matrix_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(matrix_test)
