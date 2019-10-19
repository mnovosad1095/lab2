#include "string_lib.h"

int main(int argc, char const *argv[])
{
    my_str_t str;
    my_str_create(&str, 10);
    my_str_from_cstr(&str, "aaa", 10);
    my_str_write(&str);
    return 0;
}
