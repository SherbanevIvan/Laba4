#include <stdio.h>

int main() {
    FILE *fp = fopen("test.txt", "r");
    if (fp == NULL) return 1;
    
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    
    printf("Размер файла: %ld байт\n", size);
    
    fclose(fp);
    return 0;
}