#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    int readArr[5];

    // Запись
    FILE *fp = fopen("binary.bin", "wb");
    if (fp == NULL) return 1;
    fwrite(arr, sizeof(int), n, fp);
    fclose(fp);

    // Чтение
    fp = fopen("binary.bin", "rb");
    if (fp == NULL) return 1;
    fread(readArr, sizeof(int), n, fp);
    fclose(fp);

    printf("Считанный массив: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", readArr[i]);
    }
    printf("\n");
    
    return 0;
}