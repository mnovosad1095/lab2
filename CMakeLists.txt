cmake_minimum_required(VERSION 2.8.8)

set(CMAKE_C_STANDARD 11)

add_subdirectory(Google_tests)
include_directories(Google_tests/lib/googletest/googletest/include)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(lab2 string_lib.c)
