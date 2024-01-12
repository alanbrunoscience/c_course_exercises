#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_STRING_LENGTH 41

// Functions prototype
void data_input(char **filename, int *number_students);
void allocate_memory(char **filename);
void reallocate_memory(char **filename);
int validate_mem_alloc(char *filename);
void allocate_students_info(char ***names, float **grades, int *number_students);
void fill_students_info(char ***names, float **grades, int *number_students);
void create_students_info_file(char *filename, char **names, float *grades, int number_students);
void print_content_file(char *filename);

int main() {

    char *filename, **names;
    float *grades;
    int number_students;

    data_input(&filename, &number_students);
    allocate_students_info(&names, &grades, &number_students);
    fill_students_info(&names, &grades, &number_students);
    create_students_info_file(filename, names, grades, number_students);
    print_content_file(filename);

    for (int i = 0; i < number_students; i++) {
        free(names[i]);
    }

    free(filename);
    free(names);
    free(grades);

    return 0;

}

void data_input(char **filename, int *number_students) {

    allocate_memory(filename);

    printf("*** DATA INPUT ***\n\n");
    printf("1) Enter the name of the file to be written: ");
    scanf(" %49[^\n]", *filename);

    reallocate_memory(filename);

    printf("2) Enter the number of students in the subject: ");
    scanf("%d", number_students);

}

void allocate_memory(char **filename) {

    *filename = (char *)calloc(MAX_FILENAME_LENGTH, sizeof(char));

    if(validate_mem_alloc(*filename)) {
        exit(1);
    }

}

void reallocate_memory(char **filename) {

    char *temp = strdup(*filename);

    if (temp == NULL) {
        puts("-> Memory (re)allocation failed.");
        exit(1);
    }

    free(*filename);

    *filename = temp;

}

int validate_mem_alloc(char *filename) {

    if(filename == NULL) {
        puts("-> Memory (re)allocation failed.");
        return 1;
    }

    return 0;

}

void allocate_students_info(char ***names, float **grades, int *number_students) {

    *names = (char **)calloc(*number_students, sizeof(char *));

    if (*names == NULL) {
        puts("\n-> Memory allocation failed.");
        exit(1);
    }

    *grades = (float *)calloc(*number_students, sizeof(float));

    if (*grades == NULL) {
        puts("\n-> Memory allocation failed.");
        exit(1);
    }

    for (int i = 0; i < *number_students; i++) {
        (*names)[i] = (char *)calloc(MAX_STRING_LENGTH, sizeof(char));
        if ((*names)[i] == NULL) {
            puts("\n-> Memory allocation failed.");
            exit(1);
        }
    }
}

void fill_students_info(char ***names, float **grades, int *number_students) {

    printf("\n*** STUDENTS' INFO ***\n\n");
    printf("Enter the students' information below:\n");
    
    for(int i = 0; i < *number_students; i++) {

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

void create_students_info_file(char *filename, char **names, float *grades, int number_students) {

    FILE *fptr;

    if((fptr = fopen(filename, "w")) == NULL) {
        puts("\n-> Unable to create the file.");
        exit(1);
    }

    for(int i = 0; i < number_students; i++) {
        fprintf(fptr, "Name: %40s | Grade: %.2f\n", names[i], grades[i]);
    }

    fclose(fptr);

}

void print_content_file(char *filename) {

    FILE *fptr;
    char *str = NULL;
    size_t len = 0;

    if ((fptr = fopen(filename, "r")) == NULL) {
        puts("\n-> Unable to open the file for reading.");
        exit(1);
    }

    printf("\n*** STUDENTS' INFO ***\n\n");
    while (getline(&str, &len, fptr) != -1) {
        printf("%s", str);
    }

    printf("\n");

    free(str);

    fclose(fptr);

}