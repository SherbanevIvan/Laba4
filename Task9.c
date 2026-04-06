#include <stdio.h>

int main() {
    // Создаём файл
    FILE *fp = fopen("test.txt", "w");
    fprintf(fp, "0123456789");
    fclose(fp);

    // Читаем с позиции 5
    fp = fopen("test.txt", "r");
    if (fp == NULL) return 1;
    
    fseek(fp, 5, SEEK_SET);
    char c = getc(fp);
    printf("Символ на позиции 5: %c\n", c);
    
    fclose(fp);
    return 0;
}