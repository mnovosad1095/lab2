int my_str_create(my_str_t* str, size_t buf_size) {
    str -> size_m = 0;
    str -> capacity_m = buf_size;
    str -> data = (char *) malloc(str -> capacity_m);

    return str -> data == nullptr ? - 1 : 0;
}
