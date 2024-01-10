/* FILE CONTENT

Name: Alan Bruno | Grade: 8.9
Name: Kezia Batista | Grade: 9.0
Name: Eusebio Angelo | Grade: 9
Name: Marcos Sales | Grade: 7.2
Name: Rozangela Macedo | Grade: 7.5

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50

typedef struct Students_info {

    char name[40];
    float grade;

} Students_info;

// Functions prototype
void filename_input(char **filename);
int validate_file_reading(char *filename);
void allocate_memory(char **filename);
void reallocate_memory(char **filename);
int validate_mem_alloc(char *filename);
void print_file_content(char *filename);
int count_students_file(char *filename);
void find_greatest_grade(char *filename, int *count_students, Students_info students_grades[]);

int main() {

    char *filename;

    filename_input(&filename);

    int count_students = count_students_file(filename);

    Students_info students_grades[count_students];

    find_greatest_grade(filename, &count_students, students_grades);

    free(filename);

    return 0;

}

void filename_input(char **filename) {

    allocate_memory(filename);

    printf("*** FILENAME INPUT ***\n\n");
    printf("Enter the name of the file to be read: ");
    scanf(" %[^\n]", *filename);

    if(validate_file_reading(*filename)) {
        puts("\n-> Unable to open the file for reading. Make sure that the file exists and that the name is correct. Finishing the program...");
        exit(1);
    }

    reallocate_memory(filename);

}

int validate_file_reading(char *filename) {

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

void print_file_content(char *filename) {

    FILE *fptr;
    char *str = NULL;
    size_t len = 0;

    fptr = fopen(filename, "r");

    while(getline(&str, &len, fptr) != -1) {
        printf("%s", str);
    }

    printf("\n");

    free(str);

    fclose(fptr);

}

int count_students_file(char *filename) {

    FILE *fptr;
    char name[40];
    float grade;
    int count_students = 0;

    fptr = fopen(filename, "r");

    while(fscanf(fptr, "Name: %39[^|] | Grade: %f\n", name, &grade) == 2) {
        count_students++;
    }

    fclose(fptr);

    return count_students;

}

void find_greatest_grade(char *filename, int *count_students, Students_info students_grades[]) {

    FILE *fptr;
    float highest_grade = 0.0;

    fptr = fopen(filename, "r");

    for(int i = 0; i < *count_students; i++) {
        fscanf(fptr, "Name: %39[^|] | Grade: %f\n", students_grades[i].name, &students_grades[i].grade);
    }

    fclose(fptr);

    for(int i = 0; i < *count_students; i++) {
        if(students_grades[i].grade > highest_grade) {
            highest_grade = students_grades[i].grade;
        }
    }

    printf("\n*** HIGHEST GRADE ***\n\n");
    printf("The highest grade(s) is(are) from:\n\n");
    int aux = 0;
    for(int i = 0; i < *count_students; i++) {
        if(students_grades[i].grade == highest_grade) {
            printf("%dº) Name: %s| Grade: %.2f\n", (aux + 1), students_grades[i].name, students_grades[i].grade);
            aux++;
        }
    }

}