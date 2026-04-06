#include <stdio.h>
#include <string.h>

int main() {
    char str[200];
    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);

    FILE *fp = fopen("test.txt", "w");
    if (fp == NULL) return 1;
    
    fputs(str, fp);
    fclose(fp);

    // Вывод
    fp = fopen("test.txt", "r");
    if (fp == NULL) return 1;
    
    printf("Содержимое файла:\n");
    char buffer[200];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    
    fclose(fp);
    return 0;
}