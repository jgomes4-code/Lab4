#include <stdio.h> 
extern int sum_all(int arr[], int size);

int main (void){
    char name[256];
    printf("Enter Name of String: ");
    scanf("%[^\n]%*c", name);
    printf("%s",name);

    FILE *fp = fopen(name, "r");
    if (fp == NULL){
        perror("fopen");
        return 1;
    }

    printf("File %s opened successfully\n", name);
    //char line[256];
    int size;
    int arr[256];
    size_t n = 0;

    if (fscanf(fp, "%d", &size) != 1) {
        printf("Failed to read size.\n");
        fclose(fp);
        return 1;
    }

    int i = 0;
    while (i < size && fscanf(fp, "%d", &arr[i]) == 1) {
        i++;
    }

    int sum = sum_all(arr, size);
    printf("%d\n", sum);

    return 0;
}