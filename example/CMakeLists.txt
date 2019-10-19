CMAKE_MINIMUM_REQUIRED( VERSION 3.8 )
PROJECT(my_str C)

set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../lib/)
INCLUDE_DIRECTORIES(${LIB_DIR})
set(LIBRARY ${LIB_DIR}bin/libmy_str.so)

add_executable(exp exp.c)
target_link_libraries(exp ${LIBRARY})
