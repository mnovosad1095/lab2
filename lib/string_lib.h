#include "stddef.h"
#include <stdlib.h>
#include <memory.h>
#include <stdio.h>

typedef struct
{
	size_t capacity_m; 
	size_t size_m;	   
	char*  data;	   
} my_str_t;

int my_str_create(my_str_t* str, size_t buf_size);
void my_str_free(my_str_t* str);
int my_str_getc(const my_str_t* str, size_t index);
int my_str_from_cstr(my_str_t* str, const char* cstr, size_t buf_size);
int my_str_putc(my_str_t* str, size_t index, char c);
void move_str_elements_right(char* str, size_t str_size, size_t pos, size_t n);
size_t str_len(const char* str);
int my_str_reserve(my_str_t* str, size_t buf_size);
int my_str_pushback(my_str_t* str, char c);
int my_str_popback(my_str_t* str);
void my_str_clear(my_str_t* str);
int my_str_copy(const my_str_t* from,  my_str_t* to, int reserve);
int my_str_insert_c(my_str_t* str, char c, size_t pos);
int my_str_insert(my_str_t* str, const my_str_t* from, size_t pos);
int my_str_insert_cstr(my_str_t* str, const char* from, size_t pos);
int my_str_append(my_str_t* str, const my_str_t* from);
int my_str_append_cstr(my_str_t* str, const char* from);
int my_str_substr(const my_str_t* from, my_str_t* to, size_t beg, size_t end);
int my_str_substr_cstr(const my_str_t* from, char* to, size_t beg, size_t end);
int my_str_resize(my_str_t* str, size_t new_size, char sym);
int my_str_shrink_to_fit(my_str_t* str);
size_t my_str_size(const my_str_t* str);
size_t my_str_capacity(const my_str_t* str);
int my_str_empty(const my_str_t* str);
