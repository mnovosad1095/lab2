#include "string_lib.h"

const char* my_str_get_cstr(my_str_t* str) {
    if (str == NULL) return NULL;

    str -> data[str -> size_m] = '\0';

    return str -> data;
}
size_t my_str_find_c(const my_str_t* str, char tofind, size_t from) {
    while (from < str->size_m) {
        if (my_str_getc(str, from) == tofind) {
            return from;
        }
        from++;
    }
    return (size_t)(-1);
}
int cmpfunc (const void *a, const void *b) {

    return strcmp((char *)a, (char *)b);
}

int main(int argc, char const *argv[])
{
    my_str_t text;
    my_str_create(&text, 256);

    FILE *filePointer, *resFilePointer;

    my_str_t filePath;
    my_str_create(&filePath, 100);

    my_str_append_cstr(&filePath, "../");
    my_str_append_cstr(&filePath, argv[1]);

    filePointer = fopen(my_str_get_cstr(&filePath), "r");

    if (filePointer == NULL)
        exit(EXIT_FAILURE);

    resFilePointer = fopen("../result.txt", "w");

    if (resFilePointer == NULL)
        exit(EXIT_FAILURE);

    my_str_read_file(&text, filePointer);

    my_str_t word;
    my_str_create(&word, 256);

    size_t start = 0;

    while (1) {
        if (start > text.size_m) break;

        size_t end = my_str_find_c(&text, ' ', start);
        if (end == (size_t) -1) {
            end = text.size_m;
        }
        my_str_substr(&text, &word, start, end);

        qsort(word.data, word.size_m - 1, sizeof(char), cmpfunc);

        start = end + 1;

        my_str_clear(&word);

        my_str_write_file(&word, resFilePointer);
    }

    fclose(filePointer);
    fclose(resFilePointer);

    return 0;
}
