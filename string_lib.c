#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "string_modify.h"


typedef struct
{
	size_t capacity_m; 
	size_t size_m;	   
	char*  data;	   
} my_str_t;


#include "string_info.h"

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
    printf("%u\n", str -> data);
    printf("%u\n", my_str_size(str));

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
    // size_t *p = str -> data;
    for (size_t i = 0; i < 3; i++ ){
        str -> data[i] = cstr[i];
    }

    return 0;
}

int my_str_putc(my_str_t* str, size_t index, char c){
    
}

//FUNCTIONS FOR SEARCHING AND COMPARISON//

size_t my_str_find(const my_str_t* str, const my_str_t* tofind, size_t from) {
    size_t curr = from, flag, counter = 0;

    while (curr < (str->size_m) - (tofind->size_m) && (tofind->size_m) > 0) {
        if (my_str_getc(str, curr) == my_str_getc(tofind, 0)) {
            flag = curr;
            counter = 0;
            for (size_t count = curr; count < (curr + (tofind->size_m)); count++) {
                if (my_str_getc(str, count) == my_str_getc(tofind, counter)) {
                    counter++;
                } else {
                    counter = 0;
                    flag = 0;
                    break;
                }
            }
            if (counter == tofind->size_m) {
                return flag;
            }
        }
        curr++;
    }
    return (size_t) (-1);
}

int my_str_cmp(const my_str_t* str1, const my_str_t* str2) {
    if ((str1 -> size_m) < (str2 -> size_m)) {
        return -1;
    }
    else if ((str1 -> size_m) > (str2 -> size_m)) {
        return 1;
    }
    else {
        size_t i = 0;
        while (i < str1->size_m) {
            if (my_str_getc(str1, i) == my_str_getc(str2, i)) {
                i++;
            }
            else if (my_str_getc(str1, i) < my_str_getc(str2, i)) {
                return -1;
            }
            else {
                return 1;
            }
        }
        return 0;
    }
}

int my_str_cmp_cstr(const my_str_t* str1, const char* cstr2) {
    size_t mystrlen = str1 -> size_m;
    size_t cstrlen = str_len(cstr2);

    if (mystrlen < cstrlen) {
        return -1;
    }
    else if (mystrlen > cstrlen) {
        return 1;
    }
    else {
        size_t i = 0;
        while (i < mystrlen) {
            if (my_str_getc(str1, i) == cstr2[i]) {
                i++;
            }
            else if (my_str_getc(str1, i) < cstr2[i]) {
                return -1;
            }
            else {
                return 1;
            }
        }
        return 0;
    }
}

size_t my_str_find_c(const my_str_t* str, char tofind, size_t from) {
    while (from < str->size_m) {
        if (my_str_getc(str, from) == tofind) {
            return from;
        }
        from++;
    }
    return (size_t)(-1);
}

size_t my_str_find_if(const my_str_t* str, int (*predicat)(int)) {
    for (int i = 0; i < str->size_m; i++) {
        if (predicat(my_str_getc(str, i))) {
            return (size_t)(i);
        }
    }
    return (size_t)(-1);
}
