#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

int main(int argc, char const *argv[])
{
    FILE *filePointer;
    char ch;
    int i = 0;
    char sentence[256];
    filePointer = fopen("aac.txt", "r");
    while ((ch = getc(filePointer)) != '\n')
        putchar(ch);
    fclose(filePointer);
    
    printf("%s", sentence);
    return 0;
}
