/* FILE CONTENT

São Paulo | 44420459
Rio de Janeiro | 16054524
Minas Gerais | 20538718
Bahia | 14136417
Paraná | 11443208
Rio Grande do Sul | 10880506
Pernambuco | 9058155
Ceará | 8791688
Pará | 8116132
Santa Catarina | 7609601
Goiás | 7055228
Maranhão | 6775152
Paraíba | 3974495
Amazonas | 3941175
Espírito Santo | 3833486
Mato Grosso | 3658813
Rio Grande do Norte | 3302406
Piauí | 3269200
Alagoas | 3127511
Distrito Federal | 2817068
Mato Grosso do Sul | 2756700
Sergipe | 2209558
Rondônia | 1581016
Tocantins | 1511459
Acre | 830026
Amapá | 733508
Roraima | 636303

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 50

typedef struct City {

    char name[40];
    unsigned long long population;
    
} City;

// Functions prototype
void file_names_input(char **input_file, char **output_file);
int validate_file_existence(char *file_name);
void allocate_memory(char **file_name);
void reallocate_memory(char **file_name);
int validate_mem_alloc(char *file_name);
int count_cities_file(char *input_file);
int find_most_populous_city(char *input_file, int *count_cities, City cities[]);
void create_most_pop_city_file(char *output_file, int *index, City cities[]);
void print_file_content(char *file_name);

int main() {

    char *input_file, *output_file;

    file_names_input(&input_file, &output_file);
    int count_cities = count_cities_file(input_file);

    City cities[count_cities];

    int index = find_most_populous_city(input_file, &count_cities, cities);
    create_most_pop_city_file(output_file, &index, cities);

    printf("\n\n*** CITIES DATA FILE ***\n\n");
    print_file_content(input_file);

    printf("\n\n*** MOST POPULOUS CITY ***\n\n");
    print_file_content(output_file);

    free(input_file);
    free(output_file);

    printf("\n");

    return 0;

}

void file_names_input(char **input_file, char **output_file) {

    // Allocate memory dynamically for the pointer "input_file", and "output_file"
    allocate_memory(input_file);
    allocate_memory(output_file);

    printf("*** DATA INPUT ***\n\n");
    printf("1) Enter the name of the first file to be read: ");
    scanf(" %[^\n]", *input_file);

    while(validate_file_existence(*input_file)) {
        printf("\n-> It was not possible to open the file. Make sure that this file exists or that the name is correct. Inform the name of the file again: ");
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

int validate_file_existence(char *file_name) {

    FILE *fptr;

    fptr = fopen(file_name, "r");

    if(fptr == NULL) {
        return 1;
    }

    fclose(fptr);

    return 0;
    
}

void allocate_memory(char **file_name) {
    
    *file_name = (char *)malloc(MAX_FILE_NAME_LENGTH * sizeof(char));

    if(validate_mem_alloc(*file_name)) {
        exit(1);
    }

}

void reallocate_memory(char **file_name) {

    *file_name = (char *)realloc(*file_name, (strlen(*file_name) + 1) * sizeof(char));

    if(validate_mem_alloc(*file_name)) {
        exit(1);
    }

}

int validate_mem_alloc(char *file_name) {

    if(file_name == NULL) {
        puts("\n-> Memory (re)allocation failed.");
        return 1;
    }

    return 0;

}

int count_cities_file(char *input_file) {

    FILE *fptr;
    City city;
    int count_reg = 0;

    fptr = fopen(input_file, "r");

    // Loop through the file to count the cities
    while (fscanf(fptr, "%[^|]|%llu\n", city.name, &city.population) == 2) {
        count_reg++;
    }

    fclose(fptr);

    return count_reg;

}

int find_most_populous_city(char *input_file, int *count_cities, City cities[]) {

    FILE *fptr;

    fptr = fopen(input_file, "r");

    // Read and store the cities in the array
    for (int i = 0; i < *count_cities; i++) {
        fscanf(fptr, "%[^|]|%llu\n", cities[i].name, &cities[i].population);
    }

    unsigned long long major = cities[0].population;
    int pos_major = 0;
    
    for (int i = 0; i < *count_cities; i++) {
        if(major < cities[i].population) {
            major = cities[i].population;
            pos_major = i;
        }
    }

    fclose(fptr);

    return pos_major;

}

void create_most_pop_city_file(char *output_file, int *index, City cities[]) {

    FILE *fptr;

    if((fptr = fopen(output_file, "w")) == NULL) {
        puts("\n-> Unable to open the file.");
        exit(1);
    }

    fprintf(fptr, "- City: %s\n- Population: %llu", cities[*index].name, cities[*index].population);

    fclose(fptr);

}

void print_file_content(char *file_name) {

    FILE *fptr;
    char *str = NULL;
    size_t len = 0;

    if ((fptr = fopen(file_name, "r")) == NULL) {
        puts("\n-> Unable to open the file for reading.");
        exit(1);
    }

    while (getline(&str, &len, fptr) != -1) {
        printf("%s", str);
    }

    printf("\n");

    free(str);

    fclose(fptr);

}