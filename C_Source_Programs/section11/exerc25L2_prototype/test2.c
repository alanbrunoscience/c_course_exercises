#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "");

    wchar_t first_name[] = L"alan éder MatUSAlém  ";
    wchar_t last_name[] = L"de melo rosa";
    const wchar_t delim[] = L" ,.!";
    wchar_t *saveptr_n1 = NULL;
    wchar_t *saveptr_n2 = NULL;
    wchar_t *token_n1 = wcstok(first_name, delim, &saveptr_n1);
    wchar_t *token_n2 = wcstok(last_name, delim, &saveptr_n2);
    size_t total_length = 0;

    // Calculate the total length
    while (token_n1 != NULL || token_n2 != NULL) {
        
        if (token_n1 != NULL) {
            total_length += (wcslen(token_n1) + 1);
            token_n1 = wcstok(NULL, delim, &saveptr_n1);
        }

        if (token_n2 != NULL) {
            total_length += (wcslen(token_n2) + 1);
            token_n2 = wcstok(NULL, delim, &saveptr_n2);
        }
    }

    wprintf(L"Total length: %zu\n", total_length);

    // Reset the strings
    wcscpy(first_name, L"alan éder MatUSAlém  ");
    wcscpy(last_name, L"de melo rosa");
    saveptr_n1 = NULL;
    saveptr_n2 = NULL;
    token_n1 = wcstok(first_name, delim, &saveptr_n1);
    token_n2 = wcstok(last_name, delim, &saveptr_n2);

    // Allocate memory for full_name (consider +1 for the null terminator)
    wchar_t *full_name = (wchar_t *)malloc((total_length + 1) * sizeof(wchar_t));

    if (full_name == NULL) {
        fwprintf(stderr, L"Memory allocation failed\n");
        return 1;
    }

    full_name[0] = L'\0';

    while (token_n1 != NULL) {

        for (size_t i = 0; token_n1[i] != L'\0'; i++) {
            if (i == 0) {
                token_n1[0] = towupper(token_n1[0]);
            } else {
                token_n1[i] = towlower(token_n1[i]);
            }
        }

        wcscat(full_name, token_n1);
        wcscat(full_name, L" ");
        token_n1 = wcstok(NULL, delim, &saveptr_n1);

    }

    while (token_n2 != NULL) {

        for (size_t i = 0; token_n2[i] != L'\0'; i++) {
            if (i == 0) {
                token_n2[0] = towupper(token_n2[0]);
            } else {
                token_n2[i] = towlower(token_n2[i]);
            }
        }

        wcscat(full_name, token_n2);
        wcscat(full_name, L" ");
        token_n2 = wcstok(NULL, delim, &saveptr_n2);
    
    }

    // Remove the trailing space if it exists
    if (wcslen(full_name) > 0) {
        full_name[wcslen(full_name) - 1] = L'\0';
    }

    wprintf(L"\n");

    wprintf(L"Modified string: %ls\n", full_name);
    wprintf(L"Total length: %zu\n", total_length);

    // Free the allocated memory
    free(full_name);

    return 0;
}