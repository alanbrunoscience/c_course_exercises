/* FILE CONTENT

Name: Ademir Aparecido Rosa | Year of Birth: 08-18-1967
Name: Edena Jesus de Melo Rosa | Year of Birth: 12-21-1965
Name: Vanessa Soares de Melo Rosa | Year of Birth: 09-27-1993
Name: Alan Bruno de Melo Rosa | Year of Birth: 02-25-1997
Name: Jean de Melo Rosa | Year of Birth: 06-14-1999

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50

typedef struct Birth_Dates {

    char name[50];
    int month;
    int day;
    int year;
    int age;
    
} Birth_Dates;

// Functions prototype
void data_input(char **filename);
int validade_file_existence(char *filename);
void allocate_memory(char **filename);
void reallocate_memory(char **filename);
int validate_mem_alloc(char *filename);
void date_input(int *year, int *day, int *index_mon, int months[]);
int count_people_file(char *filename);
void age_calculation(char *filename, int *total_reg, Birth_Dates people[]);
void write_ages_file(char *filename, Birth_Dates people[]);
void print_content_file(char *filename);


int main() {

    char *filename;

    data_input(&filename);
    int total_reg = count_people_file(filename);

    Birth_Dates people[total_reg];

    age_calculation(filename, &total_reg, people);

    printf("Total: %d\n", total_reg);

    free(filename);

    return 0;

}

void data_input(char **filename) {

    int year, day, index_mon;
    int *months = malloc(12 * sizeof(int));

    if(months == NULL) {
        puts("\n-> Memory allocation failed.");
        exit(1);
    }

    allocate_memory(filename);

    printf("*** FILENAME INPUT ***\n\n");
    printf("1) Enter the filename, please: ");
    scanf(" %[^\n]", *filename);

    while(validade_file_existence(*filename)) {
        printf("\n-> Unable to open the file. Make sure that the file exists or that the name is correct. Enter the filename again: ");
        scanf(" %[^\n]", *filename);
    }

    reallocate_memory(filename);

    date_input(&year, &day, &index_mon, months);

    free(months);

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

void date_input(int *year, int *day, int *index_mon, int months[]) {

    int days_of_months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for(int i = 0; i < 12; i++) {
        months[i] = days_of_months[i];
    }

    printf("\n*** DATE INPUT ***\n\n");
    printf("1) Enter the current year, please: ");
    scanf("%d", year);

    if((*year % 4 == 0 && *year % 100 != 0) || *year % 400 == 0) {
        months[1] = 29;
    }

    printf("\n2) Enter the current month (1-12), please: ");
    scanf("%d", index_mon);

    while(*index_mon < 1 || *index_mon > 12) {
        printf("\n-> The month information is invalid. Enter a correct month index (e.g. January - 1, February - 2, ...), please: ");
        scanf("%d", index_mon);
    }

    printf("\n3) Enter the current day, please: ");
    scanf("%d", day);

    while(*day < 1 || *day > (months[*index_mon - 1])) {
        printf("\n-> The day information is invalid. Enter a number between 1 and %d, please: ", months[*index_mon - 1]);
        scanf("%d", day);
    }

}

int count_people_file(char *filename) {

    FILE *fptr;
    Birth_Dates personal_info;
    int count_reg = 0;

    fptr = fopen(filename, "r");

    while(fscanf(fptr, "Name: %49[^|] | Year of Birth: %2d-%2d-%4d\n", personal_info.name, &personal_info.month, &personal_info.day, &personal_info.year) == 4) {
        count_reg++;
    }

    fclose(fptr);

    return count_reg;

}

void age_calculation(char *filename, int *total_reg, Birth_Dates people[]) {

    FILE *fptr;

    fptr = fopen(filename, "r");

    // Read and store each person's personal information in the array
    for(int i = 0; i < *total_reg; i++) {
        fscanf(fptr, "Name: %49[^|] | Year of Birth: %2d-%2d-%4d\n", personal_info.name, &personal_info.month, &personal_info.day, &personal_info.year);

        
    }



}

void write_ages_file(char *filename, Birth_Dates people[]) {

}

void print_content_file(char *filename) {

}
