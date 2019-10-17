int my_str_read_file(my_str_t* str, FILE* file);



int my_str_read_file(my_str_t* str, FILE* file){
    
    size_t size = 0;
    char ch;

    while (ch = fgetc(file) != EOF)
    {
        printf("%c", ch);
        size += 1;
    }
    printf("\n");
    

    
    // if ( fgets(str->data, size, file) == NULL ) {
    //     return -1;
    // }

    return 0; 
}


