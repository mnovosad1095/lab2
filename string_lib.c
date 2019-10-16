#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	size_t capacity_m; // Розмір блока
	size_t size_m;	   // Фактичний розмір стрічки
	char*  data;	   // Вказівник на блок пам'яті
} my_str_t;


int my_str_create(my_str_t* str, size_t buf_size);


int main(int argc, char* argv[]){
    my_str_t name;

    my_str_create(&name, 3);

    return 0;
}


int my_str_create(my_str_t* str, size_t buf_size){
    str -> size_m = buf_size;
    str -> capacity_m = buf_size * 2;
    str -> data = (char*) malloc(str -> capacity_m);
    printf("%u\n", str -> data);    
    return 0;
}




