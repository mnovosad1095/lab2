// returns string size_m
size_t my_str_size(const my_str_t* str) {
    return str -> size_m;
}

// returns string capacity
size_t my_str_capacity(const my_str_t* str) {
    return str -> capacity_m;
}

// checks whether string is empty
int my_str_empty(const my_str_t* str) {
    return str -> size_m == 0;
}

