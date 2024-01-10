#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50

// Functions prototype
void data_input(int *number_std, char **filename);
void fill_students_info(char ***names, float **grades, int *number_std);
void allocate_memory(char **filename, char ***names, float **grades, int *number_std);
void reallocate_memory(char **filename);
void create_students_info_file(char *filename, char ***names, float **grades, int *number_std);

int main() {

    char **names, *filename;
    int number_std = 0;
    float *grades;

    data_input(&number_std, &filename);
    fill_students_info(&names, &grades, &number_std);
    allocate_memory(&filename, &names, &grades, &number_std);
    create_students_info_file(filename, &names, &grades, &number_std);

    for (int i = 0; i < number_std; i++) {
        free(names[i]);
    }

    // Free memory for the array of names
    free(names);
    free(filename);
    free(grades);

    return 0;
}

void data_input(int *number_std, char **filename) {
    
    printf("*** DATA INPUT ***\n\n");
    printf("1) Enter the number of students: ");
    scanf("%d", &(*number_std));
    printf("2) Enter the name of the file to be written: ");
    scanf(" %[^\n]", *filename);

    reallocate_memory(filename);

}

void fill_students_info(char ***names, float **grades, int *number_std) {

    printf("\n*** STUDENTS' INFO ***\n\n");
    printf("Enter the students' information below:\n");

    for (int i = 0; i < *number_std; i++) {

        printf("\n%dº STUDENT:\n\n", (i + 1));
        printf("Name: ");
        scanf(" %[^\n]", (*names)[i]);

        int num_spaces = 40 - strlen((*names)[i]);

        // Fill the remaining characters with white spaces
        memset((*names)[i] + strlen((*names)[i]), ' ', num_spaces);

        printf("Grade: ");
        scanf("%f", &((*grades)[i]));

        while((*grades)[i] < 0.0 || (*grades)[i] > 10.0) {
            printf("\n-> The grade is invalid! It needs to be greater or equal to 0.0 and smaller or equal to 10.0. Enter a new grade, please: ");
            scanf("%f", &((*grades)[i]));
        }

    }

}

void allocate_memory(char **filename, char ***names, float **grades, int *number_std) {

    *filename = (char *)malloc(MAX_FILENAME_LENGTH * sizeof(char));

    if (*filename == NULL) {
        puts("\n-> Memory allocation failed.");
        exit(1);
    }

    *names = (char **)malloc((*number_std) * sizeof(char *));

    if (*names == NULL) {
        puts("\n-> Memory allocation failed.");
        exit(1);
    }

    for (int i = 0; i < *number_std; i++) {
        (*names)[i] = (char *)malloc(41 * sizeof(char));

        if ((*names)[i] == NULL) {
            puts("\n-> Memory allocation failed.");
            exit(1);
        }
    }

    *grades = (float *)malloc((*number_std) * sizeof(float));

    if (*grades == NULL) {
        puts("\n-> Memory allocation failed.");
        exit(1);
    }


}

void reallocate_memory(char **filename) {

    *filename = (char *)realloc(*filename, (strlen(*filename) + 1) * sizeof(char));

    if(*filename == NULL) {
        puts("\n-> Memory (re)allocation failed.");
        exit(1);
    }

}

void create_students_info_file(char *filename, char ***names, float **grades, int *number_std) {

    FILE *fptr;

    if((fptr = fopen(filename, "w")) == NULL) {
        puts("\n-> Unable to open the file.");
        exit(1);
    }

    for(int i = 0; i < *number_std; i++) {
        fprintf(fptr, "Name: %-40s | Grade: %.2f\n", (*names)[i], (*grades)[i]);
    }

    fclose(fptr);

}