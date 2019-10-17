#include <gtest/gtest.h>

typedef struct
{
    size_t capacity_m;
    size_t size_m;
    char*  data;
} my_str_t;

#include "../../string_info.h"

int my_str_create(my_str_t* str, size_t buf_size) {
    str -> size_m = 0;
    str -> capacity_m = buf_size;
    str -> data = (char *) malloc(str -> capacity_m);

    return str -> data == nullptr ? - 1 : 0;
}

TEST(StringInfoTests, TestStringSizeInfo) {
    my_str_t str;
    my_str_create(&str, 3);
    ASSERT_EQ(0, my_str_size(&str));
}

TEST(StringInfoTests, TestStringCapacityInfo) {
    my_str_t str;
    my_str_create(&str, 3);
    ASSERT_EQ(3, my_str_capacity(&str));
}
