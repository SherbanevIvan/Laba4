#include <stdio.h>

int main() {
    // Запись
    FILE *fp = fopen("data.txt", "w");
    if (fp == NULL) return 1;
    
    fprintf(fp, "%s %d %.2f\n", "Иван", 25, 85.5);
    fprintf(fp, "%s %d %.2f\n", "Мария", 30, 92.3);
    fclose(fp);

    // Чтение
    fp = fopen("data.txt", "r");
    if (fp == NULL) return 1;
    
    char name[50];
    int age;
    float score;
    
    while (fscanf(fp, "%s %d %f", name, &age, &score) == 3) {
        printf("Имя: %s, Возраст: %d, Оценка: %.2f\n", name, age, score);
    }
    
    fclose(fp);
    return 0;
}