#include <stdio.h>

int main() {

    FILE *fptr;
    int num, result, sum = 0;

    fptr = fopen("file.txt", "r");

    if(fptr) {

        while(!feof(fptr)) {
            result = fscanf(fptr, "%d", &num);
            printf("Result: %d\n", result);
            if(result == 1) {
                sum += num;
            }
        }

        fclose(fptr);

    } else {
        puts("File not found.");
    }

    printf("The sum of all numbers found is %d.\n", sum);

    return 0;

}