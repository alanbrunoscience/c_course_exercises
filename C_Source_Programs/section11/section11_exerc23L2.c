#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employees_info{

    char name[40];
    char profession[40];
    int length_service;

} Employees_info;

// Functions prototype
void data_input_info(int *number_emp, char filename[], Employees_info employees[]);
void print_content_file(char *filename);

int main() {

    int number_emp;
    printf("*** NUMBER OF EMPLOYEES ***\n\n");
    printf("-> Enter the number of employees: ");
    scanf("%d", &number_emp);

    char filename[] = "emp.txt";

    Employees_info employees[number_emp];

    data_input_info(&number_emp, filename, employees);

    printf("\n==== PRINT FILE CONTENT ====\n\n");
    print_content_file(filename);

    printf("\n");

    return 0;

}

void data_input_info(int *number_emp, char filename[], Employees_info employees[]) {

    FILE *fptr;

    if((fptr = fopen(filename, "w")) == NULL) {
        puts("\n-> Unable to create the file. Finishing the program...");
        exit(1);
    }

    printf("\n\n*** EMPLOYEES INFO ***\n\n");
    printf("Enter the information below:\n\n");
    for(int i = 0; i < *number_emp; i++) {
        printf("=== %dº EMPLOYEE ===\n\n", (i+1));
        printf("-> Employee's name: ");
        scanf(" %[^\n]", employees[i].name);
        printf("-> Profession: ");
        scanf(" %[^\n]", employees[i].profession);
        printf("-> Length of service (years): ");
        scanf("%d", &employees[i].length_service);
        printf("\n");
    }

    fputs("*** EMPLOYEES INFO ****\n", fptr);

    for(int i = 0; i < *number_emp; i++) {
        fprintf(fptr, "\n=== %dº EMPLOYEE ===\n\n", (i+1));
        fprintf(fptr, "-> Employee's name: %s\n", employees[i].name);
        fprintf(fptr, "-> Profession: %s\n", employees[i].profession);
        fprintf(fptr, "-> Length of service (years): %d\n", employees[i].length_service);
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

    while (getline(&str, &len, fptr) != -1) {
        printf("%s", str);
    }

    free(str);

    fclose(fptr);

}