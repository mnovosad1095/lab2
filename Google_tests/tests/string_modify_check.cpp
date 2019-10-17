#include <gtest/gtest.h>

#include "../../structure.h"
#include "../../error_constans.h"
#include "../../helper_funcs.h"
#include "../../string_general.h"
#include "../../string_info.h"
#include "../../string_modify.h"
#include "../../string_chars_usage.h"


TEST(StringModifyTests, TestStringReserve) {
    my_str_t str;
    my_str_create(&str, 8);

    // check new str
    ASSERT_EQ(8, my_str_capacity(&str));

    // check bigger str
    ASSERT_EQ(0, my_str_reserve(&str, 16));
    ASSERT_EQ(16, my_str_capacity(&str));
}

TEST(StringModifyTests, TestStringPushback) {
    my_str_t str;
    my_str_create(&str, 1);

    // check NULL reference
    ASSERT_EQ(NULL_POINTER, my_str_pushback(nullptr, 'a'));

    // check adding 'a'
    ASSERT_EQ(0, my_str_pushback(&str, 'a'));
    ASSERT_STREQ("a", str.data);
    ASSERT_EQ(1, my_str_capacity(&str));

    // check adding 'b'
    ASSERT_EQ(0, my_str_pushback(&str, 'b'));
    ASSERT_STREQ("ab", str.data);
    ASSERT_EQ(2, my_str_capacity(&str));
}


TEST(StringModifyTests, TestStringPopback) {
    my_str_t str;
    my_str_create(&str, 4);

    // fill str with word 'test'
    my_str_append_cstr(&str, "test");

    ASSERT_EQ(NULL_POINTER, my_str_popback(nullptr));

    ASSERT_EQ(4, str.size_m);

    ASSERT_EQ('t', my_str_popback(&str));
    ASSERT_EQ(3, str.size_m);
    ASSERT_STREQ("tes", my_str_get_cstr(&str));


    ASSERT_EQ('s', my_str_popback(&str));
    ASSERT_EQ(2, str.size_m);
    ASSERT_STREQ("te", my_str_get_cstr(&str));

    ASSERT_EQ('e', my_str_popback(&str));
    ASSERT_EQ(1, str.size_m);
    ASSERT_STREQ("t", my_str_get_cstr(&str));

    ASSERT_EQ('t', my_str_popback(&str));
    ASSERT_EQ(0, str.size_m);
    ASSERT_STREQ("", my_str_get_cstr(&str));
}


TEST(StringModifyTests, TestStringCopy) {
    my_str_t str, str1;
    my_str_create(&str, 4);
    my_str_create(&str1, 4);

    // fill str with word 'test'
    my_str_append_cstr(&str, "test");

    ASSERT_STREQ("test", my_str_get_cstr(&str));
    ASSERT_STREQ("", my_str_get_cstr(&str1));

    ASSERT_EQ(NULL_POINTER, my_str_copy(nullptr, &str1, 1));
    ASSERT_EQ(NULL_POINTER, my_str_copy(&str, nullptr, 1));
    ASSERT_EQ(NULL_POINTER, my_str_copy(nullptr, nullptr, 1));


    ASSERT_EQ(0, my_str_copy(&str, &str1, 1));
    ASSERT_STREQ("test", my_str_get_cstr(&str));
    ASSERT_STREQ("test", my_str_get_cstr(&str1));
}


TEST(StringModifyTests, TestStringClear) {
    my_str_t str;
    my_str_create(&str, 4);


    // fill str with word 'test'
    my_str_append_cstr(&str, "test");

    ASSERT_STREQ("test", my_str_get_cstr(&str));

    my_str_clear(&str);

    ASSERT_STREQ("", my_str_get_cstr(&str));
}


TEST(StringModifyTests, TestStringInsertChar) {
    my_str_t str;
    my_str_create(&str, 4);

    int pos = 1;
    char c = 'a';

    // fill str with word 'test'
    my_str_append_cstr(&str, "test");

    ASSERT_EQ(NULL_POINTER, my_str_insert_c(nullptr, c, pos));

    ASSERT_EQ(INDEX_ERROR, my_str_insert_c(&str, c, 10));

    ASSERT_EQ(4, str.size_m);
    ASSERT_EQ(4, str.capacity_m);

    ASSERT_EQ(0, my_str_insert_c(&str, c, pos));

    ASSERT_STREQ("taest", my_str_get_cstr(&str));
    ASSERT_EQ(5, str.size_m);
    ASSERT_EQ(8, str.capacity_m);
}

TEST(StringModifyTests, TestStringInsertSubString) {
    my_str_t str, str1;
    my_str_create(&str, 4);
    my_str_create(&str1, 11);

    int pos = 1;

    // fill str with word 'test'
    my_str_append_cstr(&str, "test");
    // fill str1 with word '_substring_'
    my_str_append_cstr(&str1, "_substring_");

    ASSERT_EQ(NULL_POINTER, my_str_insert(nullptr, &str1, pos));
    ASSERT_EQ(NULL_POINTER, my_str_insert(&str, nullptr, pos));
    ASSERT_EQ(NULL_POINTER, my_str_insert(nullptr, nullptr, pos));

    ASSERT_EQ(INDEX_ERROR, my_str_insert(&str, &str1, 10));

    ASSERT_EQ(4, str.size_m);
    ASSERT_EQ(4, str.capacity_m);

    ASSERT_EQ(0, my_str_insert(&str, &str1, pos));

    ASSERT_STREQ("t_substring_est", my_str_get_cstr(&str));
    ASSERT_EQ(15, str.size_m);
    ASSERT_EQ(15, str.capacity_m);
}



TEST(StringModifyTests, TestStringInsertCSubString) {
    my_str_t str;
    my_str_create(&str, 4);

    int pos = 1;

    // fill str with word 'test'
    my_str_append_cstr(&str, "test");

    ASSERT_EQ(NULL_POINTER, my_str_insert_cstr(nullptr, "", pos));

    ASSERT_EQ(INDEX_ERROR, my_str_insert_cstr(&str, "", 10));

    ASSERT_EQ(4, str.size_m);
    ASSERT_EQ(4, str.capacity_m);

    ASSERT_EQ(0, my_str_insert_cstr(&str, "_substring_", pos));

    ASSERT_STREQ("t_substring_est", my_str_get_cstr(&str));
    ASSERT_EQ(15, str.size_m);
    ASSERT_EQ(15, str.capacity_m);
}

TEST(StringModifyTests, TestStringAppend) {
    my_str_t str, str1;
    my_str_create(&str, 4);
    my_str_create(&str1, 11);

    // fill str with word 'test'
    my_str_append_cstr(&str, "test");
    my_str_append_cstr(&str1, "_substring_");


    ASSERT_EQ(NULL_POINTER, my_str_append(nullptr, &str1));
    ASSERT_EQ(NULL_POINTER, my_str_append(&str, nullptr));
    ASSERT_EQ(NULL_POINTER, my_str_append(nullptr, nullptr));


    ASSERT_EQ(4, str.size_m);
    ASSERT_EQ(4, str.capacity_m);

    ASSERT_EQ(0, my_str_append(&str, &str1));

    ASSERT_STREQ("test_substring_", my_str_get_cstr(&str));
    ASSERT_EQ(15, str.size_m);
    ASSERT_EQ(15, str.capacity_m);
}

TEST(StringModifyTests, TestStringCAppend) {
    my_str_t str;
    my_str_create(&str, 4);

    // fill str with word 'test'
    my_str_append_cstr(&str, "test");


    ASSERT_EQ(NULL_POINTER, my_str_append_cstr(nullptr, ""));

    ASSERT_EQ(4, str.size_m);
    ASSERT_EQ(4, str.capacity_m);

    ASSERT_EQ(0, my_str_append_cstr(&str, "_substring_"));

    ASSERT_STREQ("test_substring_", my_str_get_cstr(&str));
    ASSERT_EQ(15, str.size_m);
    ASSERT_EQ(15, str.capacity_m);
}


TEST(StringModifyTests, TestStringGetSubstring) {
    my_str_t str, str1;
    my_str_create(&str, 20);
    my_str_create(&str1, 4);

    int beg = 4, end = 14;
    // fill str with word 'test'
    my_str_append_cstr(&str, "test_substring_test");


    ASSERT_EQ(NULL_POINTER, my_str_substr(nullptr, &str1, beg, end));
    ASSERT_EQ(NULL_POINTER, my_str_substr(&str, nullptr, beg, end));
    ASSERT_EQ(NULL_POINTER, my_str_substr(nullptr, nullptr, beg, end));

    ASSERT_EQ(0, str1.size_m);
    ASSERT_EQ(4, str1.capacity_m);

    ASSERT_EQ(0, my_str_substr(&str, &str1, beg, end));

    ASSERT_STREQ("_substring_", my_str_get_cstr(&str1));
    ASSERT_EQ(11, str1.size_m);
    ASSERT_EQ(11, str1.capacity_m);
}



TEST(StringModifyTests, TestStringGetCSubstring) {
    my_str_t str;
    char substring[12];
    my_str_create(&str, 20);

    int beg = 4, end = 14;
    // fill str with word 'test'
    my_str_append_cstr(&str, "test_substring_test");

    ASSERT_EQ(NULL_POINTER, my_str_substr_cstr(nullptr, substring, beg, end));

    ASSERT_EQ(0, my_str_substr_cstr(&str, substring, beg, end));

    ASSERT_STREQ("_substring_", substring);
}
