#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <ctype.h>
#include <wctype.h>
#include <locale.h>
#include "contact_list.h"

#define MAX_NAME_LENGTH 40
#define PHONE_NUMBER_LENGTH 13

int main() {

  if (setlocale(LC_ALL, "") == NULL) {
    fwprintf(stderr, L"Failed to set locale\n");
    return 1;
  }

  int option;
  wchar_t first_name[MAX_NAME_LENGTH];
  wchar_t last_name[MAX_NAME_LENGTH];
  wchar_t *full_name = NULL;
  wchar_t phone_number[PHONE_NUMBER_LENGTH];
  int year_of_birth;
  int month_of_birth;
  int day_of_birth;
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

        wprintf(L"\n2) Last Name: ");
        wscanf(L" %l[^\n]", last_name);

        format_name_variable(first_name, &total_length);
        format_name_variable(last_name, &total_length);
        create_full_name_variable(&full_name, total_length, first_name, last_name);

        wprintf(L"\n3) Phone number (e.g.: (XX) X XXXX-XXXX)). Only digits, please: ");
        wscanf(L" %l[^\n]", phone_number);

        int validation_ret = validate_phone_number(phone_number);

        while(!validation_ret) {

          wprintf(L"\n-> Invalid phone number! Enter only the digits, please (e.g.: (XX) X XXXX-XXXX)): ");
          wscanf(L" %l[^\n]", phone_number);

          validation_ret = validate_phone_number(phone_number);

        }

        wprintf(L"\n4) Year of birth: ");
        wscanf(L" %ld", &year_of_birth);

        while(year_of_birth < 1) {
          wprintf(L"\n-> Invalid year! The year needs to be greater than 0. Enter the year again: ");
          wscanf(L" %ld", &year_of_birth);
        }

        wprintf(L"\n5) Month of birth (1 - Jan, 2 - Feb, ..., 12 - Dec): ");
        wscanf(L" %ld", &month_of_birth);

        while(month_of_birth < 1 || month_of_birth > 12) {
          wprintf(L"\n-> Invalid month! The month needs to be greater than 0 and smaller or equal to 12. Enter the month again: ");
          wscanf(L" %ld", &month_of_birth);
        }

        wprintf(L"\n6) Day of birth: ");
        wscanf(L" %ld", &day_of_birth);

        int is_leap_year  = validate_leap_year(year_of_birth);

        while(!validate_day_of_birth(is_leap_year, month_of_birth, day_of_birth)) {
          wprintf(L"\n-> Invalid day for this month! Enter the day again: ");
          wscanf(L" %ld", &day_of_birth);
        }
        
        int ret_index = get_index(full_name);
        insert_contact(&contact_list[ret_index], full_name, phone_number, year_of_birth, month_of_birth, day_of_birth);

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

    wprintf(L"\n");

  } while (option != 3);

  wprintf(L"Finishing the program...\n");

  for (int i = 0; i < 27; i++) {
    free_list(contact_list[i]);
  }

  return 0;

}