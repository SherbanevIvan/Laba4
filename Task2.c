#include <stdio.h>

int main() {
    // Запись
    FILE *fp = fopen("test.txt", "w");
    if (fp == NULL) return 1;
    
    putc('A', fp);
    putc('B', fp);
    putc('C', fp);
    putc('\n', fp);
    fclose(fp);

    // Чтение
    fp = fopen("test.txt", "r");
    if (fp == NULL) return 1;
    
    printf("Содержимое: ");
    int c;
    while ((c = getc(fp)) != EOF) {
        putchar(c);
    }
    
    fclose(fp);
    return 0;
}