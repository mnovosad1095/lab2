#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


int my_str_reserve(my_str_t* str, size_t buf_size){
    return 0;
}


int my_str_shrink_to_fit(my_str_t* str){
    str -> capacity_m = (str -> size_m + 1);

    return 0;
}


int my_str_resize(my_str_t* str, size_t new_size, char sym){


    return 0;
}