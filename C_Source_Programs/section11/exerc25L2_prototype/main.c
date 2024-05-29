#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <ctype.h>
#include <wctype.h>
#include <locale.h>
#include "contact_list.h"

#define MAX_NAME_LENGTH 40

int main() {

  if (setlocale(LC_ALL, "") == NULL) {
    fwprintf(stderr, L"Failed to set locale\n");
    return 1;
  }

  int option;
  wchar_t first_name[MAX_NAME_LENGTH];
  wchar_t last_name[MAX_NAME_LENGTH];
  wchar_t *full_name = NULL;
  size_t total_length;

  Node* contact_list[27];

  initialize_lists(contact_list);

  do {

    wprintf(L"*** OPTIONS MENU ***\n\n");
    wprintf(L"1 - Insert contact;\n");
    wprintf(L"2 - Print contact list;\n");
    wprintf(L"3 - Finish the program.\n\n-> ");
    wscanf(L"%d", &option);

    switch (option) {

      case 1:

        total_length = 0;

        wprintf(L"\n*** CONTACT INFO ***\n\n");
        wprintf(L"1) First Name: ");
        wscanf(L" %l[^\n]", first_name);

        wprintf(L"2) Last Name: ");
        wscanf(L" %l[^\n]", last_name);

        format_name_variable(first_name, &total_length);
        format_name_variable(last_name, &total_length);
        create_full_name_variable(&full_name, total_length, first_name, last_name);

        int ret_index = get_index(full_name);

        insert_contact(&contact_list[ret_index], full_name);

        free(full_name);

        break;
      
      case 2:

        print_list(contact_list);
            
        break;

      default:

        if (option != 3) {
          wprintf(L"\n-> Invalid option!\n");
        }

    }

    wprintf(L"\n\n");

  } while (option != 3);

  wprintf(L"Finishing the program...\n");

  for (int i = 0; i < 27; i++) {
    free_list(contact_list[i]);
  }

  return 0;

}