#include "string_lib.h"


void move_str_elements_right(char* str, size_t str_size, size_t pos, size_t n) {
    if (str == NULL) return;

    for (size_t i = str_size - 1; i > pos - 1; --i) {
        str[i + n] = str[i];
    }
}

size_t str_len(const char* str) {
    if (str == NULL) return (size_t) NULL_POINTER;

    size_t i = 0;
    while (str[i] != '\0') i++;

    return i;
}

void str_copy(char* from, char* to, size_t length) {
    for (size_t i = 0; i < length; ++i) to[i] = from[i];
}

void str_copy_c(const char* from, char* to, size_t length) {
    for (size_t i = 0; i < length; ++i) to[i] = from[i];
}