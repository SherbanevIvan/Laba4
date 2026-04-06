#include <stdio.h>

int main() {
    // Запись
    FILE *fp = fopen("test.txt", "w");
    if (fp == NULL) return 1;
    
    fputs("Первая строка\n", fp);
    fputs("Вторая строка\n", fp);
    fclose(fp);

    // Чтение
    fp = fopen("test.txt", "r");
    if (fp == NULL) return 1;
    
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    
    fclose(fp);
    return 0;
}