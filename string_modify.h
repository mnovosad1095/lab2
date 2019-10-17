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

int my_str_resize(my_str_t* str, size_t new_size, char sym){
    char *new_buffer = (char *) malloc(new_size);

    if (new_buffer == NULL) {
        return -1;
    }

    if (new_size <= str->size_m){
        memmove(new_buffer, str -> data, new_size);
    } else {
        memmove(new_buffer, str -> data, str -> size_m);
        for (size_t i = str->size_m; i < new_size; i++) {
            new_buffer[i] = sym;
        }
    }

    return 0;
}

int my_str_pushback(my_str_t* str, char c) {
    if (str == NULL) {
        return -1;
    }

    if (str -> size_m == str -> capacity_m) {
        my_str_reserve(str, str -> capacity_m * 2);
    }

    str -> data[str -> size_m++] = c;
}


int my_str_popback(my_str_t* str) {
    if (str == NULL) {
        return -1;
    } else if (str -> size_m == 0) {
        return -2;
    }

    return str -> data[str -> size_m--];
}


int my_str_copy(const my_str_t* from,  my_str_t* to, int reserve) {
    if (!my_str_empty(to)) {
        my_str_clear(to);
    }

    size_t capacity = (!reserve && to -> capacity_m >= from -> capacity_m) ? to -> capacity_m : from -> capacity_m;

    if (my_str_reserve(to, capacity) == -1) return -1;

    memmove(from -> data, to -> data, from -> size_m);

    return 0;
}

void my_str_clear(my_str_t* str) {
    str -> size_m = 0;
}

int my_str_insert_c(my_str_t* str, char c, size_t pos) {
    // check whether given pos not out of our string
    if (pos >= str -> size_m || pos < 0) return -2;
    // reserve bigger buffer if needed
    if (my_str_reserve(str, str -> size_m + 1) == -1) return -1;

    // move chars right
    move_str_elements_right(str -> data, str -> size_m, pos, 1);

    // insert char on given position
    str -> data[pos] = c;

    // increase str size
    str -> size_m++;

    return 0;
}

int my_str_insert(my_str_t* str, const my_str_t* from, size_t pos) {
    // check whether given pos not out of our string
    if (pos >= str -> size_m || pos < 0) return -2;
    // reserve bigger buffer if needed
    if (my_str_reserve(str, str -> size_m + from -> size_m) == -1) return -1;

    // move chars right
    move_str_elements_right(str -> data, str -> size_m, pos, from -> size_m);

    // insert substring on given position
    memmove(str -> data + pos, from -> data, from -> size_m);

    // increase str size
    str -> size_m += from -> size_m;

    return 0;
}


int my_str_insert_cstr(my_str_t* str, const char* from, size_t pos) {
    // check whether given pos not out of our string
    if (pos >= str -> size_m || pos < 0) return -2;

    size_t from_length = str_len(from);
    // reserve bigger buffer if needed
    if (my_str_reserve(str, str -> size_m + from_length) == -1) return -1;

    // move chars right
    move_str_elements_right(str -> data, str -> size_m, pos, from_length);

    // insert substring on given position
    memmove(str -> data + pos, from, from_length);

    // increase str size
    str -> size_m += from_length;

    return 0;
}

int my_str_append(my_str_t* str, const my_str_t* from) {
    // reserve bigger buffer if needed
    if (my_str_reserve(str, str -> size_m + from -> size_m) == -1) return -1;

    // append string
    memmove(str -> data + str -> size_m, from -> data, from -> size_m);

    str -> size_m += from -> size_m;

    return 0;
}



int my_str_append_cstr(my_str_t* str, const char* from) {
    size_t from_length = str_len(from);

    // reserve bigger buffer if needed
    if (my_str_reserve(str, str -> size_m + from_length) == -1) return -1;

    // append string
    memmove(str -> data + str -> size_m, from, from_length);

    str -> size_m += from_length;

    return 0;
}

int my_str_substr(const my_str_t* from, my_str_t* to, size_t beg, size_t end) {
    // check whether given pos not out of our string
    if (beg >= from -> size_m || beg < 0) return -2;

    size_t sub_str_len = end - beg + 1;

    // reserve bigger buffer if needed
    if (my_str_reserve(to, sub_str_len) == -1) return -1;

    memmove(to -> data, from -> data + beg, sub_str_len);

    return 0;
}

int my_str_substr_cstr(const my_str_t* from, char* to, size_t beg, size_t end) {
    // check whether given pos not out of our string
    if (beg >= from -> size_m || beg < 0) return -2;

    memmove(to, from -> data + beg, end - beg + 1);

    return 0;
}


void move_str_elements_right(char* str, size_t str_size, size_t pos, size_t n) {
    for (size_t i = str_size - 1; i > pos - 1; --i) {
        str[i + n] = str[i];
    }
}

size_t str_len(const char* str) {
    size_t i = 0;
    while (str[i] != '\0') i++;

    return i;
}