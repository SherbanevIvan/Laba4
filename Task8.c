#include <stdio.h>

typedef struct {
    char name[50];
    int age;
} Person;

int main() {
    Person people[] = {{"Иван", 25}, {"Мария", 30}, {"Петр", 35}};
    int n = 3;
    Person readPeople[3];

    // Запись
    FILE *fp = fopen("people.bin", "wb");
    if (fp == NULL) return 1;
    fwrite(people, sizeof(Person), n, fp);
    fclose(fp);

    // Чтение
    fp = fopen("people.bin", "rb");
    if (fp == NULL) return 1;
    fread(readPeople, sizeof(Person), n, fp);
    fclose(fp);

    printf("Список:\n");
    for (int i = 0; i < n; i++) {
        printf("%s, %d лет\n", readPeople[i].name, readPeople[i].age);
    }
    
    return 0;
}