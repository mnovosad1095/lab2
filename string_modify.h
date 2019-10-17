int my_str_reserve(my_str_t* str, size_t buf_size) {
    if (buf_size <= str -> capacity_m) {
        return 0;
    }

    char *new_buffer = (char *) malloc(buf_size);

    if (new_buffer == NULL) {
        return -1;
    }

    memmove(new_buffer, str -> data, str -> size_m);

    str -> capacity_m = buf_size;

    free(str -> data);

    str -> data = new_buffer;

    return 0;
}