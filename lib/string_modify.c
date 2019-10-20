#include "string_lib.h"


// void move_str_elements_right(char* str, size_t str_size, size_t pos, size_t n);
// size_t str_len(const char* str);
// int my_str_reserve(my_str_t* str, size_t buf_size);
// int my_str_pushback(my_str_t* str, char c);
// int my_str_popback(my_str_t* str);
// void my_str_clear(my_str_t* str);
// int my_str_copy(const my_str_t* from,  my_str_t* to, int reserve);
// int my_str_insert_c(my_str_t* str, char c, size_t pos);
// int my_str_insert(my_str_t* str, const my_str_t* from, size_t pos);
// int my_str_insert_cstr(my_str_t* str, const char* from, size_t pos);
// int my_str_append(my_str_t* str, const my_str_t* from);
// int my_str_append_cstr(my_str_t* str, const char* from);
// int my_str_substr(const my_str_t* from, my_str_t* to, size_t beg, size_t end);
// int my_str_substr_cstr(const my_str_t* from, char* to, size_t beg, size_t end);
// int my_str_resize(my_str_t* str, size_t new_size, char sym);
// int my_str_shrink_to_fit(my_str_t* str);
//const int NULL_POINTER = -1;
//const int NO_MEMORY_LEFT = -2;
//const int INDEX_ERROR = -3;


int my_str_reserve(my_str_t* str, size_t buf_size) {
    if (str == NULL) return NULL_POINTER;

    if (buf_size <= str -> capacity_m) {
        return 0;
    }

    char *new_buffer = (char *) malloc(buf_size + 1);

    if (new_buffer == NULL) {
        return NO_MEMORY_LEFT;
    }

    memmove(new_buffer, str -> data, str -> size_m);

    str -> capacity_m = buf_size;

    free(str -> data);

    str -> data = new_buffer;

    return 0;
}

int my_str_resize(my_str_t* str, size_t new_size, char sym){
    if (str == NULL) return NULL_POINTER;

    char *new_buffer = (char *) malloc(new_size + 1);

    if (new_buffer == NULL) {
        return NO_MEMORY_LEFT;
    }

    if (new_size < str->size_m){

        memmove(new_buffer, str -> data, new_size);

    } else if(new_size == str->size_m){

        return 0;

    } else {

        memmove(new_buffer, str -> data, str -> size_m);

        for (size_t i = str->size_m; i < new_size; i++) {
            // fill empty memory with given symbol
            new_buffer[i] = sym;
        }

    }

    free(str -> data);
    str -> data = new_buffer;
    str -> size_m = new_size;

    return 0;
}

int my_str_shrink_to_fit(my_str_t* str){
    if (str == NULL) return NULL_POINTER;

    char *new_buffer = (char *) malloc(str -> size_m);
    
    if (new_buffer == NULL) {
        return -1;
    }

    memmove(new_buffer, str -> data, str -> size_m);
    
    free(str -> data);
    str -> data = new_buffer;
    str -> capacity_m = str -> size_m;

    return 0;
}


int my_str_pushback(my_str_t* str, char c) {
    if (str == NULL) {
        return NULL_POINTER;
    }

    if (str -> size_m == str -> capacity_m) {
        my_str_reserve(str, str -> capacity_m * 2);
    }

    str -> data[str -> size_m++] = c;

    return 0;
}


int my_str_popback(my_str_t* str) {
    if (str == NULL) {
        return NULL_POINTER;
    } else if (str -> size_m == 0) {
        return INDEX_ERROR;
    }

    return str -> data[--str -> size_m];
}


int my_str_copy(const my_str_t* from,  my_str_t* to, int reserve) {
    if (from == NULL || to == NULL) return NULL_POINTER;

    if (!my_str_empty(to)) my_str_clear(to);

    size_t capacity = (!reserve && to -> capacity_m >= from -> capacity_m) ? to -> capacity_m : from -> capacity_m;

    if (my_str_reserve(to, capacity) == NO_MEMORY_LEFT) return NO_MEMORY_LEFT;

    str_copy(from -> data, to -> data, from -> size_m);

    to -> size_m = from -> size_m;

    return 0;
}

void my_str_clear(my_str_t* str) {
    str -> size_m = 0;
}

int my_str_insert_c(my_str_t* str, char c, size_t pos) {
    if (str == NULL) return NULL_POINTER;

    // check whether given pos not out of our string
    if (pos >= str -> size_m) return INDEX_ERROR;
    // reserve bigger buffer if needed
    if (str -> size_m == str -> capacity_m) {
        if(my_str_reserve(str, str -> capacity_m * 2) == NO_MEMORY_LEFT) return NO_MEMORY_LEFT;
    }

    // move chars right
    move_str_elements_right(str -> data, str -> size_m, pos, 1);

    // insert char on given position
    str -> data[pos] = c;

    // increase str size
    str -> size_m++;

    return 0;
}

int my_str_insert(my_str_t* str, const my_str_t* from, size_t pos) {
    if (str == NULL || from == NULL) return NULL_POINTER;

    // check whether given pos not out of our string
    if (pos >= str -> size_m) return INDEX_ERROR;
    // reserve bigger buffer if needed
    if (my_str_reserve(str, str -> size_m + from -> size_m) == NO_MEMORY_LEFT) return NO_MEMORY_LEFT;

    // move chars right
    move_str_elements_right(str -> data, str -> size_m, pos, from -> size_m);

    // insert substring on given position
    memmove(str -> data + pos, from -> data, from -> size_m);

    // increase str size
    str -> size_m += from -> size_m;

    return 0;
}


int my_str_insert_cstr(my_str_t* str, const char* from, size_t pos) {
    if (str == NULL || from == NULL) return NULL_POINTER;

    // check whether given pos not out of our string
    if (pos >= str -> size_m) return INDEX_ERROR;

    size_t from_length = str_len(from);
    // reserve bigger buffer if needed
    if (my_str_reserve(str, str -> size_m + from_length) == NO_MEMORY_LEFT) return NO_MEMORY_LEFT;

    // move chars right
    move_str_elements_right(str -> data, str -> size_m, pos, from_length);

    // insert substring on given position
    str_copy_c(from, str -> data + pos, from_length);

    // increase str size
    str -> size_m += from_length;

    return 0;
}

int my_str_append(my_str_t* str, const my_str_t* from) {
    if (str == NULL || from == NULL) return NULL_POINTER;

    // reserve bigger buffer if needed
    if (my_str_reserve(str, str -> size_m + from -> size_m) == NO_MEMORY_LEFT) return NO_MEMORY_LEFT;

    // append string
    str_copy(from -> data, str -> data + str -> size_m, from -> size_m);

    str -> size_m += from -> size_m;

    return 0;
}



int my_str_append_cstr(my_str_t* str, const char* from) {
    if (str == NULL || from == NULL) return NULL_POINTER;

    size_t from_length = str_len(from);

    // reserve bigger buffer if needed
    if (my_str_reserve(str, str -> size_m + from_length) == NO_MEMORY_LEFT) return NO_MEMORY_LEFT;

    // append string
    str_copy_c(from, str -> data + str -> size_m, from_length);

    str -> size_m += from_length;

    return 0;
}

int my_str_substr(const my_str_t* from, my_str_t* to, size_t beg, size_t end) {
    if (from == NULL || to == NULL) return NULL_POINTER;

    // check whether given pos not out of our string
    if (beg >= from -> size_m) return INDEX_ERROR;

    size_t sub_str_len = end - beg + 1;

    // reserve bigger buffer if needed
    if (my_str_reserve(to, sub_str_len) == NO_MEMORY_LEFT) return NO_MEMORY_LEFT;

    str_copy(from -> data + beg, to -> data, sub_str_len);

    to -> size_m = sub_str_len;

    return 0;
}

int my_str_substr_cstr(const my_str_t* from, char* to, size_t beg, size_t end) {
    if (from == NULL || to == NULL) return NULL_POINTER;

    // check whether given pos not out of our string
    if (beg >= from -> size_m) return INDEX_ERROR;

    size_t sub_str_len = end - beg + 1;

    str_copy(from -> data + beg, to,  sub_str_len);

    to[sub_str_len] = '\0';

    return 0;
}

//
//void move_str_elements_right(char* str, size_t str_size, size_t pos, size_t n) {
//    for (size_t i = str_size - 1; i > pos - 1; --i) {
//        str[i + n] = str[i];
//    }
//}
//
//size_t str_len(const char* str) {
//    size_t i = 0;
//    while (str[i] != '\0') i++;
//
//    return i;
//}

