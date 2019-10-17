#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "structure.h"
#include "error_constans.h"
#include "helper_funcs.h"
#include "string_info.h"
#include "string_modify.h"


int my_str_create(my_str_t* str, size_t buf_size);
void mys_str_free(my_str_t* str);
int my_str_getc(const my_str_t* str, size_t index);
int my_str_from_cstr(my_str_t* str, const char* cstr, size_t buf_size);
int my_str_putc(my_str_t* str, size_t index, char c);
void do_smth(my_str_t* str);


int main(int argc, char* argv[]){
//    my_str_t str;
//    char k[3] = "abc";
//
//    my_str_create(&str, 3);
//    my_str_from_cstr(&str, k, 3);
//    printf("%c\n", my_str_getc(&str, 2));
//
//    my_str_reserve(&str, str.capacity_m * 2);
//
//    my_str_insert_c(&str, 'd', 2);
//    printf("%s", str.data);
    return 0;
}


int my_str_create(my_str_t* str, size_t buf_size) {
    str -> size_m = 0;
    str -> capacity_m = buf_size * 2;
    str -> data = (char *) malloc(str -> capacity_m);

    return 0;
}


int my_str_getc(const my_str_t* str, size_t index) {
    if (index > str -> size_m) {
        return -1;
    }

    return (int) str -> data[index];
}


int my_str_from_cstr(my_str_t* str, const char* cstr, size_t buf_size){
    //TODO MAKE RESIZE

    if (buf_size == 0) { 
        buf_size = sizeof(cstr); 
    } else if (buf_size < sizeof(cstr)) {
        return -1;
    } 
    my_str_resize(str, buf_size, '0');

    for (size_t i = 0; i < buf_size; i++ ){
        str -> data[i] = cstr[i];
    }
    
    return 0;
}


int my_str_getc(const my_str_t* str, size_t index) {
    if (index > str -> size_m - 1) { return -1; }

    return (int) str -> data[index];
}


int my_str_putc(my_str_t* str, size_t index, char c){
}


void do_smth(my_str_t* str){
    printf("%d", my_str_getc(str, 1));
}



