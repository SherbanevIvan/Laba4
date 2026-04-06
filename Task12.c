#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
} Person;

int main() {
    Person p;
    int choice;
    
    do {
        printf("\n1. Добавить запись\n");
        printf("2. Показать все записи\n");
        printf("0. Выход\n");
        printf("Выбор: ");
        scanf("%d", &choice);
        getchar();
        
        if (choice == 1) {
            printf("Имя: ");
            fgets(p.name, 50, stdin);
            p.name[strcspn(p.name, "\n")] = 0;
            printf("Возраст: ");
            scanf("%d", &p.age);
            getchar();
            
            FILE *fp = fopen("database.bin", "ab");
            if (fp != NULL) {
                fwrite(&p, sizeof(Person), 1, fp);
                fclose(fp);
                printf("Добавлено!\n");
            }
        }
        else if (choice == 2) {
            FILE *fp = fopen("database.bin", "rb");
            if (fp == NULL) {
                printf("Файл пуст\n");
                continue;
            }
            printf("\n--- Записи ---\n");
            while (fread(&p, sizeof(Person), 1, fp) == 1) {
                printf("%s, %d лет\n", p.name, p.age);
            }
            fclose(fp);
        }
        
    } while (choice != 0);
    
    return 0;
}