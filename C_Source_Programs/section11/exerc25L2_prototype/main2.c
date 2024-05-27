#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

#define MAX_NAME_LENGTH 40

void format_name_variable(wchar_t name[], size_t* total_length);
void create_full_name_variable(wchar_t** full_name, size_t total_length, wchar_t first_name[], wchar_t last_name[]);

int main() {

  setlocale(LC_ALL, "");

  int option;
  wchar_t first_name[MAX_NAME_LENGTH];
  wchar_t last_name[MAX_NAME_LENGTH];
  wchar_t *full_name = NULL;
  size_t total_length;

  do {

    wprintf(L"*** OPTIONS MENU ***\n\n");
    wprintf(L"1 - Insert contact;\n");
    wprintf(L"2 - Finish the program.\n\n-> ");
    scanf("%d", &option);

    switch (option) {

    case 1:

      total_length = 0;

      wprintf(L"\n*** CONTACT INFO ***\n\n");
      wprintf(L"1) First Name: ");
      scanf(" %l[^\n]", first_name);

      wprintf(L"2) Last Name: ");
      scanf(" %l[^\n]", last_name);

      format_name_variable(first_name, &total_length);
      format_name_variable(last_name, &total_length);
      create_full_name_variable(&full_name, total_length, first_name, last_name);

      wprintf(L"\nFull name: %ls\n", full_name);

      free(full_name);

      break;

    default:

      if (option != 2) {
        wprintf(L"\n-> Invalid option!\n");
      }

    }

    wprintf(L"\n\n");

  } while (option != 2);

  wprintf(L"Finishing the program...\n");

  return 0;
}

void format_name_variable(wchar_t name[], size_t* total_length) {

  wchar_t str[MAX_NAME_LENGTH];
  wcscpy(str, name);
  const wchar_t delim[] = L" ,.!";
  wchar_t *saveptr = NULL;
  wchar_t *token = wcstok(str, delim, &saveptr);
  
  while (token != NULL) {
    *total_length += (wcslen(token) + 1);
    token = wcstok(NULL, delim, &saveptr);
  }

  wcscpy(str, name);
  saveptr = NULL;
  token = wcstok(str, delim, &saveptr);

  name[0] = L'\0';

  while (token != NULL) {
    for (size_t i = 0; token[i] != L'\0'; i++) {
      if (i == 0) {
        token[0] = towupper(token[0]);
      } else {
        token[i] = towlower(token[i]);
      }
    }

    wcscat(name, token);
    wcscat(name, L" ");
    token = wcstok(NULL, delim, &saveptr);
  }

  if (wcslen(name) > 0) {
    name[wcslen(name) - 1] = L'\0';
  }

}

void create_full_name_variable(wchar_t** full_name, size_t total_length, wchar_t first_name[], wchar_t last_name[]) {

  *full_name = (wchar_t *)malloc(total_length * sizeof(wchar_t));

  if (*full_name == NULL) {
    fwprintf(stderr, L"Memory allocation failed\n");
    return;
  }

  (*full_name)[0] = L'\0';

  wcscpy(*full_name, first_name);
  wcscat(*full_name, L" ");
  wcscat(*full_name, last_name);

  // if (wcslen(*full_name) > 0 && (*full_name)[wcslen(*full_name) - 1] == L' ') {
  //   (*full_name)[wcslen(*full_name) - 1] = L'\0';
  // }

}