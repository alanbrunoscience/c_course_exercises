#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <stdlib.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "");

    wchar_t str[] = L"HeLlo, world! This is a sample string.";
    const wchar_t delim[] = L" ,.!";
    wchar_t *saveptr = NULL;
    wchar_t *token = wcstok(str, delim, &saveptr);
    size_t total_length = 0;

    while (token != NULL) {
        total_length += wcslen(token) + 1;
        token = wcstok(NULL, delim, &saveptr);
    }

    wcscpy(str, L"HeLlo, world! This is a sample string.");
    saveptr = NULL;
    token = wcstok(str, delim, &saveptr);

    wchar_t *new_str = (wchar_t *)malloc(total_length * sizeof(wchar_t));

    if (new_str == NULL) {
        fwprintf(stderr, L"Memory allocation failed\n");
        return 1;
    }

    new_str[0] = L'\0';

    while (token != NULL) {

        for (size_t i = 0; token[i] != L'\0'; i++) {
            if (i == 0) {
                token[0] = towupper(token[0]);
            } else {
                token[i] = towlower(token[i]);
            }
        }

        wcscat(new_str, token);
        wcscat(new_str, L" ");
        token = wcstok(NULL, delim, &saveptr);

    }

    if (wcslen(new_str) > 0) {
        new_str[wcslen(new_str) - 1] = L'\0';
    }


    wprintf(L"Modified string: %ls\n", new_str);
    wprintf(L"Total length: %ld\n", total_length);

    // Free the allocated memory
    free(new_str);

    return 0;
}
