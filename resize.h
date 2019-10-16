#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


// typedef struct
// {
// 	size_t capacity_m; 
// 	size_t size_m;	   
// 	char*  data;	   
// } my_str_t;


int my_str_reserve(my_str_t* str, size_t buf_size){
    return 0;
}


int my_str_shrink_to_fit(my_str_t* str){
    str -> capacity_m = (str -> size_m + 1);
    
    return 0;
}