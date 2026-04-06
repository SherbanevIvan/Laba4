#include <stdio.h>

typedef struct {
    char name[50];
    int age;
} Person;

int main() {
    Person p1 = {"Алексей", 28};
    Person p2;

    // Запись
    FILE *fp = fopen("person.bin", "wb");
    if (fp == NULL) return 1;
    fwrite(&p1, sizeof(Person), 1, fp);
    fclose(fp);

    // Чтение
    fp = fopen("person.bin", "rb");
    if (fp == NULL) return 1;
    fread(&p2, sizeof(Person), 1, fp);
    fclose(fp);

    printf("Считано: %s, %d лет\n", p2.name, p2.age);
    return 0;
}