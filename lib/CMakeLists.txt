cmake_minimum_required(VERSION 3.12)
project(my_str C)

set(CMAKE_C_STANDARD 11)
set(my_str_FILES string_lib.h string_lib.c string_modify.c
    string_info.c read_write.c)

set(LIBRARY_OUTPUT_PATH ../bin)
add_library(my_str SHARED ${my_str_FILES})