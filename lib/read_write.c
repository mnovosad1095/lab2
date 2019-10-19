#include "string_lib.h"


// int my_str_read_file(my_str_t* str, FILE* file);
// int my_str_read(my_str_t* str);
// int my_str_write_file(const my_str_t* str, FILE* file);
// int my_str_write(const my_str_t* str);
// int my_str_read_file_delim(my_str_t* str, FILE* file, char delimiter);


int my_str_read_file(my_str_t* str, FILE* file) {
    if(file == NULL || str == NULL){
        return -1;
    }
    
    char ch;
    int res;

    while ((ch = getc(file)) != EOF)
    {
        //append it to the end of string
        res = my_str_pushback(str, (char)ch);
        // return error if append didn't work well
        if (res == -1){
            return -2;
        }
    }

    return 0;
    
}

int my_str_read(my_str_t* str) {
    char ch;
    int res;

    while ((ch = getc(stdin)) != '\n')
    {
        //append it to the end of string
        res = my_str_pushback(str, (char)ch);
        // return error if append didn't work well
        if (res == -1){
            return -2;
        }
    }

    return 0;
    
}

int my_str_write_file(const my_str_t* str, FILE* file) {
    if (str == NULL){
        return -1;
    }

    int res;
    
    res = fputs(str -> data, file);

    if (res == EOF) {
        return -2;
    }

    return 0;

}

int my_str_write(const my_str_t* str) {
    if (str == NULL) {
        return -1;
    }

    printf("%s", str -> data);

    return 0;
}

int my_str_read_file_delim(my_str_t* str, FILE* file, char delimiter) {
    if(file == NULL || str == NULL){
        return -1;
    }
    
    char ch;
    int res;
    int currrent = 0;

    // read char by char from file
    while ((ch = getc(file)) != EOF && currrent != delimiter )
    {
        //append it to the end of string
        res = my_str_pushback(str, (char)ch);
        currrent++;
        
        if (res == -1){
            return -2;
        }
    }

    return 0; 
}