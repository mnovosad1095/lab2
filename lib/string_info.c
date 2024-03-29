#include "string_lib.h"

//const int NULL_POINTER = -1;
//const int NO_MEMORY_LEFT = -2;
//const int INDEX_ERROR = -3;

// returns string size_m
size_t my_str_size(const my_str_t* str) {
    if (str == NULL) return (size_t) NULL_POINTER;

    return str -> size_m;
}

// returns string capacity
size_t my_str_capacity(const my_str_t* str) {
    if (str == NULL) return (size_t) NULL_POINTER;

    return str -> capacity_m;
}

// checks whether string is empty
int my_str_empty(const my_str_t* str) {
    if (str == NULL) return NULL_POINTER;

    return str -> size_m == 0;
}

