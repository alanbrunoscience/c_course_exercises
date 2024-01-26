/* FILE CONTENT

Alan Bruno de Melo Rosa
7.8
9.6
10.0
4.5

*/

#include "sorting_exerc22L2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50

// Functions prototype
void filenames_rw_input(char **input_file, char **output_file);
int validate_file_existence(char *filename);
int allocate_memory(char **filename);
int reallocate_memory(char **filename);
int count_number_grades(char *input_file);
void read_file_info(char *input_file, char *output_file, int *number_grades, float **grades);
void alloc_mem_grades_array(char *input_file, char *output_file, int *number_grades, float **grades);
void validate_content_file(char *input_file, char *output_file, float *grades);
void create_new_file(char *input_file, char *output_file, int *number_grades, float *grades);
int print_content_file(char *filename);

int main() {

    char *input_file, *output_file;
    float *grades;
    
    filenames_rw_input(&input_file, &output_file);
    int number_grades = count_number_grades(input_file);
    read_file_info(input_file, output_file, &number_grades, &grades);

    printf("\n*** CONTENT OF THE READ FILE ***\n\n");
    int error_code = print_content_file(input_file);

    if(error_code) {
        free(input_file);
        free(output_file);
        free(grades);
        exit(1);
    }
    
    quicksort(grades, 0, number_grades - 1);

    create_new_file(input_file, output_file, &number_grades, grades);

    printf("\n*** CONTENT OF THE EDITED FILE ***\n\n");
    error_code = print_content_file(output_file);

    if(error_code) {
        free(input_file);
        free(output_file);
        free(grades);
        exit(1);
    }

    free(input_file);
    free(output_file);
    free(grades);

    return 0;

}

void filenames_rw_input(char **input_file, char **output_file) {

    if(allocate_memory(input_file)) {

        puts("\n-> Memory allocation failed.");
        exit(1);

    } else {

        printf("*** FILENAME INPUT ***\n\n");
        printf("1) Enter the name of the file to be read: ");
        scanf(" %[^\n]", *input_file);

        if(validate_file_existence(*input_file)) {
            printf("\n-> Unable to open the file. Make sure that the file exists or that the name is correct. Finishing the program...\n");
            free(*input_file);
            exit(1);
        }

        if(reallocate_memory(input_file)){
            puts("\n-> Memory reallocation failed.");
            free(*input_file);
            exit(1);
        }

    }

    if(allocate_memory(output_file)) {

        puts("\n-> Memory allocation failed.");
        free(*input_file);
        exit(1);

    } else {

        printf("2) Enter the name of the file to be written: ");
        scanf(" %[^\n]", *output_file);

        while(strcmp(*input_file, *output_file) == 0) {
            printf("\n-> The name of this file is the same as the file provided previously. So, the second will overwrite the first. Enter a different name for the second file, please: ");
            scanf(" %[^\n]", *output_file);
        }

        if(reallocate_memory(output_file)){
            puts("\n-> Memory reallocation failed.");
            free(*input_file);
            free(*output_file);
            exit(1);
        }

    }
    
}

int validate_file_existence(char *filename) {

    FILE *fptr;

    fptr = fopen(filename, "r");

    if(fptr == NULL) {
        return 1;
    }

    fclose(fptr);

    return 0;

}

int allocate_memory(char **filename) {

    *filename = (char *)malloc(MAX_FILENAME_LENGTH * sizeof(char));

    if(*filename == NULL) {
        return 1;
    }

    return 0;

}

int reallocate_memory(char **filename) {

    *filename = (char *)realloc(*filename, (strlen(*filename) + 1) * sizeof(char));

    if(*filename == NULL) {
        return 1;
    }

    return 0;

}

int count_number_grades(char *input_file) {

    FILE *fptr;
    char *first_line = NULL;
    size_t len = 0;
    int count = 0;
    float grade;

    fptr = fopen(input_file, "r");

    if (getline(&first_line, &len, fptr) == -1) {
        
        free(first_line);
        fclose(fptr);
        
        return count;

    } else {

        while(fscanf(fptr, "%f", &grade) == 1) {
            count++;
        }

        free(first_line);
        fclose(fptr);

        return count;

    }       

}

void read_file_info(char *input_file, char *output_file, int *number_grades, float **grades) {

    FILE *fptr;
    char *first_line = NULL;
    size_t len = 0;
    int count = 0;
    float grade;
    
    alloc_mem_grades_array(input_file, output_file, number_grades, grades);
    validate_content_file(input_file, output_file, *grades);

    if (getline(&first_line, &len, (fptr = fopen(input_file, "r"))) == -1) {

        free(first_line);
        fclose(fptr);

    } else {
        
        while(fscanf(fptr, "%f", &grade) == 1)
            (*grades)[count++] = grade;

        free(first_line);
        fclose(fptr);

    }
}

void alloc_mem_grades_array(char *input_file, char *output_file, int *number_grades, float **grades) {

    *grades = (float *)calloc(*number_grades, sizeof(float));

    if(*grades == NULL) {
        puts("\n-> Memory allocation failed.");
        free(input_file);
        free(output_file);
        exit(1);
    }

}

void validate_content_file(char *input_file, char *output_file, float *grades) {

    FILE *fptr;

    fptr = fopen(input_file, "r");

    fseek(fptr, 0, SEEK_END);

    long file_size = ftell(fptr);

    if (file_size == 0) {
        puts("\n-> The file is empty.");
        free(input_file);
        free(output_file);
        free(grades);
        fclose(fptr);
        exit(1);
    }

    fclose(fptr);

}

void create_new_file(char *input_file, char *output_file, int *number_grades, float *grades) {
 
    FILE *fptr1, *fptr2;
    char *student_name = NULL;
    size_t len = 0;

    if((fptr1 = fopen(output_file, "w")) == NULL) {
        puts("\n-> Unable to open the file.");
        free(input_file);
        free(output_file);
        free(grades);
        exit(1);
    }
    
    fputs("*** STUDENT'S INFO ****\n\n", fptr1);

    fptr2 = fopen(input_file, "r");

    getline(&student_name, &len, fptr2);

    fprintf(fptr1, "-> Student's Name: %s\n", student_name);

    fputs("*** GRADES SORTED ****\n\n", fptr1);

    for(int i = 0; i < *number_grades; i++) {
        fprintf(fptr1, "%dº) %.2f\n", (i+1), grades[i]);
    }

    free(student_name);

    fclose(fptr1);
    fclose(fptr2);

    printf("\n");

}

int print_content_file(char *filename) {

    FILE *fptr;
    char *str = NULL;
    size_t len = 0;

    if ((fptr = fopen(filename, "r")) == NULL) {
        puts("\n-> Unable to open the file for reading.");
        return 1;
    }

    while (getline(&str, &len, fptr) != -1) {
        printf("%s", str);
    }

    printf("\n");

    free(str);

    fclose(fptr);

    return 0;

}