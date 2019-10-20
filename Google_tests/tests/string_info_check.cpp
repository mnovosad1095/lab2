#include <gtest/gtest.h>

#include "../lib/string_lib.h"

TEST(StringInfoTests, TestStringSizeInfo) {
    my_str_t str;
    my_str_create(&str, 1);

    // check NULL pointer
    ASSERT_EQ((size_t) NULL_POINTER, my_str_size(nullptr));

    // check empty string
    ASSERT_EQ(0, my_str_size(&str));

    // check not empty string
    my_str_pushback(&str, 'a');
    ASSERT_EQ(1, my_str_size(&str));
}

TEST(StringInfoTests, TestStringCapacityInfo) {
    my_str_t str;
    my_str_create(&str, 3);

    // check NULL pointer
    ASSERT_EQ((size_t) NULL_POINTER, my_str_capacity(nullptr));

    // check empty string
    ASSERT_EQ(3, my_str_capacity(&str));

    // check not empty string
    my_str_append_cstr(&str, "abcd");
    ASSERT_EQ(4, my_str_capacity(&str));

}

TEST(StringInfoTests, TestStringIsEmptyInfo) {
    my_str_t str;
    my_str_create(&str, 1);

    // check NULL pointer
    ASSERT_EQ(NULL_POINTER, my_str_empty(nullptr));

    // check empty string
    ASSERT_EQ(1, my_str_empty(&str));

    // check not empty string
    my_str_pushback(&str, 'a');
    ASSERT_EQ(0, my_str_empty(&str));
}
