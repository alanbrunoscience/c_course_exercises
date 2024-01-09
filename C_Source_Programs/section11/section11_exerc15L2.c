/* FILE CONTENT

Name: Ademir Aparecido Rosa | Year of Birth: 11-18-1969
Name: Edena Jesus de Melo Rosa | Year of Birth: 12-21-1965
Name: Vanessa Soares de Melo Rosa | Year of Birth: 09-27-1993
Name: Alan Bruno de Melo Rosa | Year of Birth: 02-25-1997
Name: Jean de Melo Rosa | Year of Birth: 06-14-1999
Name: Alice Soares Rodrigues | Year of Birth: 11-13-2022

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
void filenames_input(char **input_file, char **output_file);
int validade_file_existence(char *filename);
void allocate_memory(char **filename);
void reallocate_memory(char **filename);
int validate_mem_alloc(char *filename);
void date_input(int months[], int *year, int *index_mon, int *day);
int count_people_file(char *input_file);
void age_calculation(char *input_file, int *total_reg, int *year, int *index_mon, int *day, Birth_Dates people[]);
void write_ages_categories_file(char *output_file, int *total_reg, Birth_Dates people[]);
void print_content_file(char *output_file);

int main() {

    char *input_file, *output_file;
    int year, day, index_mon;
    int *months = malloc(12 * sizeof(int));

    if(months == NULL) {
        puts("\n-> Memory allocation failed.");
        exit(1);
    }
    
    filenames_input(&input_file, &output_file);
    date_input(months, &year, &index_mon, &day);

    int total_reg = count_people_file(input_file);
    Birth_Dates people[total_reg];

    age_calculation(input_file, &total_reg, &year, &index_mon, &day, people);
    write_ages_categories_file(output_file, &total_reg, people);
    print_content_file(output_file);

    free(input_file);
    free(output_file);
    free(months);

    return 0;

}

void filenames_input(char **input_file, char **output_file) {

    allocate_memory(input_file);
    allocate_memory(output_file);

    printf("*** FILENAMES INPUT ***\n\n");
    printf("1) Enter the name of the first file to be read: ");
    scanf(" %[^\n]", *input_file);

    while(validade_file_existence(*input_file)) {
        printf("\n-> Unable to open the file. Make sure that the file exists or that the name is correct. Enter the filename again: ");
        scanf(" %[^\n]", *input_file);
    }

    reallocate_memory(input_file);

    printf("\n2) Enter the name of the file to be written: ");
    scanf(" %[^\n]", *output_file);

    while(strcmp(*input_file, *output_file) == 0) {
        printf("\n-> The name of this file is the same as the file provided previously. So, the content of the second will overwrite the first. Enter a different name for the second file, please: ");
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

void date_input(int months[], int *year, int *index_mon, int *day) {

    int days_of_months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for(int i = 0; i < 12; i++) {
        months[i] = days_of_months[i];
    }

    printf("\n\n*** DATE INPUT ***\n\n");
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

int count_people_file(char *input_file) {

    FILE *fptr;
    Birth_Dates personal_info;
    int count_reg = 0;

    fptr = fopen(input_file, "r");

    while(fscanf(fptr, "Name: %49[^|] | Year of Birth: %2d-%2d-%4d\n", personal_info.name, &personal_info.month, &personal_info.day, &personal_info.year) == 4) {
        count_reg++;
    }

    fclose(fptr);

    return count_reg;

}

void age_calculation(char *input_file, int *total_reg, int *year, int *index_mon, int *day, Birth_Dates people[]) {

    FILE *fptr;
    int dif_years = 0;

    fptr = fopen(input_file, "r");

    // Read and store each person's personal information in the array
    for(int i = 0; i < *total_reg; i++) {
        fscanf(fptr, "Name: %49[^|] | Year of Birth: %2d-%2d-%4d\n", people[i].name, &people[i].month, &people[i].day, &people[i].year);

        dif_years = *year - people[i].year;

        if(people[i].month > *index_mon) {
            dif_years -= 1;
            people[i].age = dif_years;
        }

        if(people[i].month == *index_mon) {
            if(people[i].day > *day) {
                dif_years -= 1;
                people[i].age = dif_years;
            } else {
                people[i].age = dif_years;
            }
        }

        if(*index_mon > people[i].month) {
            people[i].age = dif_years;
        }

    }

    fclose(fptr);

}

void write_ages_categories_file(char *output_file, int *total_reg, Birth_Dates people[]) {

    FILE *fptr;

    if((fptr = fopen(output_file, "w")) == NULL) {
        puts("\n-> Unable to open the file.");
        exit(1);
    }

    for(int i = 0; i < *total_reg; i++) {
        if(people[i].age < 18) {
            fprintf(fptr, "%dº) Name: %s | Year of Birth: %d-%d-%d | Current Age: %d year(s) old | Category: Under Age\n", i+1, people[i].name, people[i].month, people[i].day, people[i].year, people[i].age);
        } else if (people[i].age > 18) {
            fprintf(fptr, "%dº) Name: %s | Year of Birth: %d-%d-%d | Current Age: %d year(s) old | Category: Over 18\n", i+1, people[i].name, people[i].month, people[i].day, people[i].year, people[i].age);
        } else {
            fprintf(fptr, "%dº) Name: %s | Year of Birth: %d-%d-%d | Current Age: %d year(s) old | Category: Coming Of Age\n", i+1, people[i].name, people[i].month, people[i].day, people[i].year, people[i].age);
        }
    }
        
    fclose(fptr);

}

void print_content_file(char *output_file) {

    FILE *fptr;
    char *str = NULL;
    size_t len = 0;

    if ((fptr = fopen(output_file, "r")) == NULL) {
        puts("\n-> It was not possible to open the file for reading.");
        exit(1);
    }

    printf("\n\n*** PRINT GENERATED FILE CONTENT ***\n\n");
    while (getline(&str, &len, fptr) != -1) {
        printf("%s", str);
    }

    printf("\n");

    free(str);

    fclose(fptr);

}