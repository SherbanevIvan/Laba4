#include <stdio.h>

int main() {
    FILE *fp = fopen("test.txt", "r");
    if (fp == NULL) return 1;
    
    int c;
    while ((c = getc(fp)) != EOF) {
        putchar(c);
    }
    
    if (feof(fp)) {
        printf("\n[Достигнут конец файла]\n");
    }
    if (ferror(fp)) {
        printf("Ошибка при чтении!\n");
    }
    
    fclose(fp);
    return 0;
}