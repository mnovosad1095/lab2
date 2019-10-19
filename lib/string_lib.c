// #include <stddef.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <memory.h>
// #include <wchar.h>
// #include "structure.h"
// #include "string_info.h"
// #include "string_modify.h"
// #include "read_write.h"

#include "string_lib.h"

// int my_str_create(my_str_t* str, size_t buf_size);
// void my_str_free(my_str_t* str);
// int my_str_getc(const my_str_t* str, size_t index);
// int my_str_from_cstr(my_str_t* str, const char* cstr, size_t buf_size);
// int my_str_putc(my_str_t* str, size_t index, char c);



int my_str_create(my_str_t* str, size_t buf_size) {
    str -> size_m = 0;
    str -> capacity_m = buf_size * 2;
    str -> data = (char *) malloc(str -> capacity_m);

    if (str -> data == NULL) {
        return -1;
    }

    return 0;
}


int my_str_from_cstr(my_str_t* str, const char* cstr, size_t buf_size){

    if (buf_size == 0) { 
        buf_size = sizeof(cstr); 
    } else if (buf_size < sizeof(cstr)) {
        return -1;
    } 
    
    char *new_buffer = (char *) malloc(buf_size);

    size_t len = str_len(cstr);
    
    memmove(new_buffer, cstr, len);
    
    str -> data = new_buffer;
    str -> size_m = len;
    
    return 0;
}


int my_str_getc(const my_str_t* str, size_t index) {
    if (index > str -> size_m - 1) { return -1; }

    return (int) str -> data[index];
}


int my_str_putc(my_str_t* str, size_t index, char c){
}
