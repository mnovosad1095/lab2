#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "resize.h"


int my_str_create(my_str_t* str, size_t buf_size);
void mys_str_free(my_str_t* str);
int my_str_getc(const my_str_t* str, size_t index);
int my_str_from_cstr(my_str_t* str, const char* cstr, size_t buf_size);
int my_str_putc(my_str_t* str, size_t index, char c);
void do_smth(my_str_t* str);


int main(int argc, char* argv[]){
    my_str_t name;
    char k[3] = "abc";

    my_str_create(&name, 3);
    my_str_from_cstr(&name, k, 4);

    printf("%c\n", my_str_getc(&name, 2));

    // my_str_putc(&name, 2, 'k');
    // printf("%d\n", my_str_getc(&name, 3));
    printf("%s\n", name.data);
    do_smth(&name);
    

    return 0;
}


int my_str_create(my_str_t* str, size_t buf_size) {
    str -> size_m = buf_size;
    str -> capacity_m = buf_size * 2;
    str -> data = (char*) malloc(str -> capacity_m + 1);

    return 0;
}


void my_str_free(my_str_t* str){
    free(str -> data);
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
    if (index > str->size_m - 1 || index < 0) {
        return -1;
    } else {
        str -> data[index] = c; 
    }
    
    return 0;
}


void do_smth(my_str_t* str){
    printf("%d", my_str_getc(str, 1));
}



