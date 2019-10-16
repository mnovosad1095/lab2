#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	size_t capacity_m; 
	size_t size_m;	   
	char*  data;	   
} my_str_t;


int my_str_create(my_str_t* str, size_t buf_size);
int my_str_getc(const my_str_t* str, size_t index);
int my_str_from_cstr(my_str_t* str, const char* cstr, size_t buf_size);
int my_str_putc(my_str_t* str, size_t index, char c);


int main(int argc, char* argv[]){
    my_str_t name;
    char k[3] = "abc";

    my_str_create(&name, 3);
    my_str_from_cstr(&name, k, 3);
    printf("%c\n", my_str_getc(&name, 2));
    return 0;
}


int my_str_create(my_str_t* str, size_t buf_size) {
    str -> size_m = buf_size;
    str -> capacity_m = buf_size * 2;
    str -> data = (char*) malloc(str -> capacity_m);

    return 0;
}


int my_str_getc(const my_str_t* str, size_t index) {
    if (index > str -> size_m) {
        return -1;
    }

    return (int) str->data[index];
}


int my_str_from_cstr(my_str_t* str, const char* cstr, size_t buf_size){
    //TODO MAKE RESIZE
    // size_t *p = str -> data;
    for (size_t i = 0; i < 3; i++ ){
        str -> data[i] = cstr[i];
    }

    return 0;
}

int my_str_putc(my_str_t* str, size_t index, char c){
    
}




