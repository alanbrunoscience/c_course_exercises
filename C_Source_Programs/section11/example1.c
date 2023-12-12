#include <stdio.h>

int main() {
    FILE *fptr;
    char ch;

    fptr = fopen("test.txt", "w");

    if (fptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter text (press Enter to finish):\n");

    while ((ch = getchar()) != '\n') {
        fputc(ch, fptr); // It writes character by character in the file.
    }

    fclose(fptr);

    return 0;
}
