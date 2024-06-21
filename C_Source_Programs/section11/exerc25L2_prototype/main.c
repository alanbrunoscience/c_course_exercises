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
  int year_of_birth = 0;
  int month_of_birth = 0;
  int day_of_birth = 0;
  int list_index;
  int check_records_list;
  size_t total_length;

  Node* contact_list[27];

  initialize_lists(contact_list);

  do {

    wprintf(L"*** OPTIONS MENU ***\n\n");
    wprintf(L"1 - Insert contact;\n");
    wprintf(L"2 - Remove contact;\n");
    wprintf(L"3 - Print contact list;\n");
    wprintf(L"4 - Finish the program.\n\n-> ");
    wscanf(L"%d", &option);

    switch (option) {

      case 1:

        total_length = 0;

        wprintf(L"\n\n*** CONTACT INFO ***\n\n");
        first_and_last_name_input(first_name, last_name, &total_length, &full_name);
        phone_number_input(phone_number);
        date_info_entry_validation(&year_of_birth, &month_of_birth, &day_of_birth);

        list_index = get_index(full_name);

        int is_contact_registered = update_existing_contact(&contact_list[list_index], full_name, phone_number, year_of_birth, month_of_birth, day_of_birth);

        if(!is_contact_registered) {

          int is_there_contact = find_contacts_same_phone_number(contact_list, phone_number);

          if(is_there_contact) {

            int yes_no = 0;

            wprintf(L"\n\n-> Would you want to continue registering this contact (1 - Yes / 2 - No)? ");
            wscanf(L" %d", &yes_no);

            while(yes_no < 1 || yes_no > 2) {
              wprintf(L"\n-> Incorrect answer! Choose an option between 1 (Yes) or 2 (No): ");
              wscanf(L" %d", &yes_no);
            }

            if(yes_no == 1) {
              insert_contact(&contact_list[list_index], full_name, phone_number, year_of_birth, month_of_birth, day_of_birth);
            } else {
              wprintf(L"\n-> Aborting the registration operation...\n\n");
              free(full_name);
              break;
            }
          } else {
            insert_contact(&contact_list[list_index], full_name, phone_number, year_of_birth, month_of_birth, day_of_birth);
          }
          
        }

        free(full_name);

        // Step to sort the lists
        for (size_t i = 0; i < 27; i++) {
          Node *current = contact_list[i];
          if(current != NULL && current -> next != NULL) {
            merge_sort(&contact_list[i]);
          }
        }  

        break;

      case 2:

        check_records_list = is_the_list_empty(contact_list);

        if(check_records_list) {

          total_length = 0;

          wprintf(L"\n\n*** CONTACT TO BE REMOVED ***\n\n");
          first_and_last_name_input(first_name, last_name, &total_length, &full_name);
          phone_number_input(phone_number);

          list_index = get_index(full_name);

          if(contact_list[list_index] == NULL) {
            
            wprintf(L"\n-> Non-existent contact!\n\n");
            
            free(full_name);
            
            break;

          } else {

            int node_found = remove_contact(&contact_list[list_index], full_name, phone_number);

            if(!node_found) {
              wprintf(L"\n-> Non-existent contact!\n\n");  
            }

            free(full_name);

          }

        } else {
          wprintf(L"\n-> The list is empty!\n\n");
        }
            
        break;
      
      case 3:

        check_records_list = is_the_list_empty(contact_list);

        if(check_records_list) {
          print_list(contact_list);
        } else {
          wprintf(L"\n-> The list is empty!\n\n");
        }

        break;

      default:

        if (option != 4) {
          wprintf(L"\n-> Invalid option!\n");
        }

    }

    wprintf(L"\n");

  } while (option != 4);

  wprintf(L"Finishing the program...\n");

  for (int i = 0; i < 27; i++) {
    free_list(contact_list[i]);
  }

  return 0;

}