#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <ctype.h>
#include <wctype.h>
#include <locale.h>

int main() {

    if (setlocale(LC_ALL, "") == NULL) {
        fwprintf(stderr, L"Failed to set locale\n");
        return 1;
    }

    FILE *fptr;
    wchar_t buffer[256];
    wchar_t name[50];
    wchar_t *full_name = NULL;
    wchar_t phone_number[12];
    int day_of_birth, month_of_birth, year_of_birth;

    if ((fptr = fopen("contacts.bin", "rb")) == NULL) {
        wprintf(L"Could not open file.\n");
        return 1;
    }

    // Read the file line by line
    while (fgetws(buffer, sizeof(buffer) / sizeof(wchar_t), fptr) != NULL) {

        // Look for the name line
        if (wcsstr(buffer, L"-> Name:") != NULL) {
            swscanf(buffer, L"-> Name: %l[^;];", name);
        }

        // Look for the phone number line
        if (wcsstr(buffer, L"-> Phone Number:") != NULL) {
            swscanf(buffer, L"-> Phone Number: %l[^;];", phone_number);
        }

        // Look for the birthday date line
        if (wcsstr(buffer, L"-> Birthday date:") != NULL) {
            swscanf(buffer, L"-> Birthday date: %d/%d/%d;", &month_of_birth, &day_of_birth, &year_of_birth);
        }
    }

    fclose(fptr);

    full_name = (wchar_t *)realloc(full_name, (wcslen(name) + 1) * sizeof(wchar_t));

    if (full_name == NULL) {
        fwprintf(stderr, L"\n\n-> Memory allocation failed.\n");
        exit(1);
    }

    wcscpy(full_name, name);

    wprintf(L"Full Name: %ls\n", full_name);
    wprintf(L"Phone Number: %ls\n", phone_number);
    wprintf(L"Month of Birth: %d\n", month_of_birth);
    wprintf(L"Day of Birth: %d\n", day_of_birth);
    wprintf(L"Year of Birth: %d\n", year_of_birth);

    free(full_name);

    printf("Teste\n");

    return 0;

}