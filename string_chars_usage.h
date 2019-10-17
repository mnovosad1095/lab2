const char* my_str_get_cstr(my_str_t* str);



const char* my_str_get_cstr(my_str_t* str) {
    if (str == NULL) return NULL;

    str -> data[str -> size_m] = '\0';

    return str -> data;
}