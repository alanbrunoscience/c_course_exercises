/* FILE CONTENT

Alan Bruno de Melo Rosa
9
7
10

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50

// Functions prototype
void filenames_rw_input(char **input_file, char **output_file);
int validate_file_existence(char *filename);
void allocate_memory(char **filename);
void reallocate_memory(char **filename);
int validate_mem_alloc(char *filename);
int count_number_grades(char *input_file);
void read_file_info(char *filename, int number_grades, float **grades);

int main() {

    char *input_file, *output_file;
    float *grades;
    
    filenames_rw_input(&input_file, &output_file);
    int number_grades = count_number_grades(input_file);
    read_file_info(input_file, number_grades, &grades);

    free(input_file);
    free(output_file);
    free(grades);

    return 0;

}

void filenames_rw_input(char **input_file, char **output_file) {

    allocate_memory(input_file);
    allocate_memory(output_file);

    printf("*** FILENAME INPUT ***\n\n");
    printf("1) Enter the name of the file to be read: ");
    scanf(" %[^\n]", *input_file);

    if(validate_file_existence(*input_file)) {
        printf("\n-> Unable to open the file. Make sure that the file exists or that the name is correct. Finishing the program...");
        exit(1);
    }

    reallocate_memory(input_file);

    printf("2) Enter the name of the file to be written: ");
    scanf(" %[^\n]", *output_file);

    while(strcmp(*input_file, *output_file) == 0) {
        printf("\n-> The name of this file is the same as the file provided previously. So, the second will overwrite the first. Enter a different name for the second file, please: ");
        scanf(" %[^\n]", *output_file);
    }

    reallocate_memory(output_file);
    
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

void allocate_memory(char **filename) {

    *filename = (char *)malloc(MAX_FILENAME_LENGTH * sizeof(char));

    if(validate_mem_alloc(*filename)) {
        exit(1);
    }

}

void reallocate_memory(char **filename) {

    *filename = (char *)realloc(*filename, (strlen(*filename) + 1) * sizeof(char));

    if(validate_mem_alloc(*filename)) {
        exit(1);
    }

}

int validate_mem_alloc(char *filename) {

    if(filename == NULL) {
        puts("\n-> Memory (re)allocation failed.");
        return 1;
    }

    return 0;

}

int count_number_grades(char *input_file) {

    FILE *fptr;
    int count = 0;
    float grade;
    char line[41];

    fptr = fopen(input_file, "r");

    // Skip the first line (student's name)
    if (fgets(line, sizeof(line), fptr) == NULL) {
        // Handle error or return count if the file is empty
        fclose(fptr);
        return count;
    }

    while(fscanf(fptr, "%f", &grade) == 1) {
        count++;
    }

    fclose(fptr);

    return count;    

}

void read_file_info(char *filename, int number_grades, float **grades) {

    FILE *fptr;
    float grade;
    char line[41];

    printf("%d\n", number_grades);
    
    *grades = (float *)calloc(number_grades, sizeof(float));

    if(*grades == NULL) {
        puts("\n-> Memory allocation failed.");
        exit(1);
    }

    fptr = fopen(filename, "r");

    if (fgets(line, sizeof(line), fptr) == NULL) {
        puts("\n-> The file is empty!");
        fclose(fptr);
        exit(1);
    }
 
    int count = 0;

    while(fscanf(fptr, "%f", &grade) == 1) {
        *grades[count++] = grade;
    }

    printf("\n");

    for(int i = 0; i < number_grades; i++) {
        printf("%.2f ", (*grades)[i]);
    }

    fclose(fptr);
    
}