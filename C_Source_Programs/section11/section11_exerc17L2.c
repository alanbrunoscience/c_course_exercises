/* FILE CONTENT 

3 3 2
1 0
1 2

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50

// Functions prototype
void filenames_input(char **input_file, char **output_file);
int validade_file_existence(char *filename);
void allocate_memory(char **filename);
void reallocate_memory(char **filename);
int validate_mem_alloc(char *filename);
void read_matrix_dimensions(char *input_file, char *output_file);
void write_matrix_file(char *output_file, int *i, int *j, int canceled_pos[][2], int *num_rows);
void print_content_file(char *output_file);

int main() {

    char *input_file, *output_file;

    filenames_input(&input_file, &output_file);
    read_matrix_dimensions(input_file, output_file);
    print_content_file(output_file);

    free(input_file);
    free(output_file);

    return 0;

}

void filenames_input(char **input_file, char **output_file) {

    allocate_memory(input_file);
    allocate_memory(output_file);

    printf("*** FILENAME INPUT ***\n\n");
    printf("1) Enter the name of the file to be read: ");
    scanf(" %[^\n]", *input_file);

    while(validade_file_existence(*input_file)) {
        printf("\n-> Unable to open the file. Make sure that the file exists or that the name is correct. Enter the filename again: ");
        scanf(" %[^\n]", *input_file);
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

int validade_file_existence(char *filename) {

    FILE *fptr;

    if((fptr = fopen(filename, "r")) == NULL) {
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

void read_matrix_dimensions(char *input_file, char *output_file) {

    FILE *fptr;
    char c;
    int i = 0, j = 0, num_rows;

    fptr = fopen(input_file, "r");
    
    fscanf(fptr, "%d %d %d", &i, &j, &num_rows);

    int canceled_pos[num_rows][2];

    while((c = fgetc(fptr)) != EOF) {
        for(int row = 0; row < num_rows; row++) {
            for (int col = 0; col < 2; col++) {
                fscanf(fptr, "%d", &canceled_pos[row][col]);
                /*if (fscanf(fptr, "%d", &canceled_pos[row][col]) != 1) {
                    fprintf(stderr, "Error reading from file\n");
                    fclose(fptr);
                    return;
                }*/
            }
        }
    }

    fclose(fptr);

    write_matrix_file(output_file, &i, &j, canceled_pos, &num_rows);

}

void write_matrix_file(char *output_file, int *i, int *j, int canceled_pos[][2], int *num_rows) {

    FILE *fptr;
    int array2D[*i][*j];

    if((fptr = fopen(output_file, "w")) == NULL) {
        puts("\n-> Unable to create the file.");
        exit(1);
    }

    for(int row = 0; row < *i; row++) {
        for(int col = 0; col < *j; col++) {
            array2D[row][col] = 1;
        }
    }

    for(int k = 0; k < *num_rows; k++) {
        array2D[canceled_pos[k][0]][canceled_pos[k][1]] = 0;
    }

    for(int row = 0; row < *i; row++) {
        for(int col = 0; col < *j; col++) {
            fprintf(fptr, "%d ", array2D[row][col]);
        }
        fputc('\n', fptr);
    }

    fclose(fptr);

}

void print_content_file(char *output_file) {

    FILE *fptr;
    char *str = NULL;
    size_t len = 0;

    if ((fptr = fopen(output_file, "r")) == NULL) {
        puts("\n-> Unable to open the file for reading.");
        exit(1);
    }

    printf("\n*** PRINT GENERATED FILE CONTENT ***\n\n");
    while (getline(&str, &len, fptr) != -1) {
        printf("%s", str);
    }

    printf("\n");

    free(str);

    fclose(fptr);

}