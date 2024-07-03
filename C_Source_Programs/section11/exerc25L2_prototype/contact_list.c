#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <ctype.h>
#include <wctype.h>
#include <locale.h>
#include "contact_list.h"

#define MAX_NAME_LENGTH 40

void initialize_lists(Node *contact_list[]) {
  for (size_t i = 0; i < 27; i++) {
    contact_list[i] = NULL;
  }
}

void first_and_last_name_input(wchar_t *first_name, wchar_t *last_name, size_t *total_length, wchar_t **full_name) {

  wprintf(L"1) First Name: ");
  wscanf(L" %l[^\n]", first_name);

  wprintf(L"\n2) Last Name: ");
  wscanf(L" %l[^\n]", last_name);

  format_name_variable(first_name, total_length);
  format_name_variable(last_name, total_length);
  create_full_name_variable(full_name, *total_length, first_name, last_name);

}

void format_name_variable(wchar_t name[], size_t *total_length) {

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

void create_full_name_variable(wchar_t **full_name, size_t total_length, wchar_t first_name[], wchar_t last_name[]) {

  *full_name = (wchar_t *)malloc(total_length * sizeof(wchar_t));

  if (*full_name == NULL) {
    fwprintf(stderr, L"\n-> Memory allocation failed\n");
    exit(1);
  }

  (*full_name)[0] = L'\0';

  wcscpy(*full_name, first_name);
  wcscat(*full_name, L" ");
  wcscat(*full_name, last_name);

}

void phone_number_input(wchar_t *phone_number) {

  wprintf(L"\n3) Phone number (e.g.: (XX) X XXXX-XXXX)). Only digits, please: ");
  wscanf(L" %l[^\n]", phone_number);

  int validation_ret = validate_phone_number(phone_number);

  while(!validation_ret) {

    wprintf(L"\n-> Invalid phone number! Enter only the digits, please (e.g.: (XX) X XXXX-XXXX)): ");
    wscanf(L" %l[^\n]", phone_number);

    validation_ret = validate_phone_number(phone_number);

  }

}

int validate_phone_number(wchar_t phone_number[]) {

  int count_valid_digits = 0;

  for(size_t i = 0; phone_number[i] != '\0'; i++) {
    
    if(phone_number[i] >= 48 && phone_number[i] <= 57) {
      count_valid_digits++;
    }

  }

  if(count_valid_digits == 11 && wcslen(phone_number) == 11) {
    return 1;
  } else {
    return 0;
  }

}

void date_info_entry_validation(int *year_of_birth, int *month_of_birth, int *day_of_birth) {

  wprintf(L"\n4) Year of birth: ");
  wscanf(L" %ld", year_of_birth);

  while(*year_of_birth < 1) {
    wprintf(L"\n-> Invalid year! The year needs to be greater than 0. Enter the year again: ");
    wscanf(L" %ld", year_of_birth);
  }

  wprintf(L"\n5) Month of birth (1 - Jan, 2 - Feb, ..., 12 - Dec): ");
  wscanf(L" %ld", month_of_birth);

  while(*month_of_birth < 1 || *month_of_birth > 12) {
    wprintf(L"\n-> Invalid month! The month needs to be greater than 0 and smaller or equal to 12. Enter the month again: ");
    wscanf(L" %ld", month_of_birth);
  }

  wprintf(L"\n6) Day of birth: ");
  wscanf(L" %ld", day_of_birth);

  int is_leap_year = validate_leap_year(*year_of_birth);

  while(!validate_day_of_birth(is_leap_year, *month_of_birth, *day_of_birth)) {
    wprintf(L"\n-> Invalid day for this month! Enter the day again: ");
    wscanf(L" %ld", day_of_birth);
  }

}

int validate_leap_year(int year_of_birth) {
  if((year_of_birth % 4 == 0 && year_of_birth % 100 != 0) || year_of_birth % 400 == 0) {
    return 1;
  } else {
    return 0;
  }
}

int validate_day_of_birth(int is_leap_year, int month_of_birth, int day_of_birth) {

  int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if(is_leap_year) {
    months[1] = 29;
  }

  int index_month = month_of_birth - 1;

  if(day_of_birth < 1 || day_of_birth > months[index_month]) {
    return 0;
  } else {
    return 1;
  }

}

int get_index(wchar_t word[]) {

  wchar_t first_letter = word[0];

  if(first_letter == L'Ä' || first_letter == L'Á' || first_letter == L'À' || first_letter == L'Â' || first_letter == L'Ã') {
    return 0;
  } else if(first_letter == L'Ç') {
    return 2;
  } else if(first_letter == L'É' || first_letter == L'Ê' || first_letter == L'Ë' || first_letter == L'È') {
    return 4;
  } else if(first_letter == L'Í' || first_letter == L'Î' || first_letter == L'Ï' || first_letter == L'Ì') {
    return 8;
  } else if(first_letter == L'Ñ') {
    return 13;
  } else if(first_letter == L'Ö' || first_letter == L'Ó' || first_letter == L'Ô' || first_letter == L'Ò') {
    return 14;
  } else if(first_letter == L'Ü' || first_letter == L'Ú' || first_letter == L'Û' || first_letter == L'Ù') {
    return 20;
  } else if(first_letter == L'Ý') {
    return 24;
  } else if(first_letter >= 65 && first_letter <= 90) {
    return (first_letter - L'A');
  } else {
    return 26; // Elements that deviate from the common standard for names
  }

}

Node *create_node(wchar_t *full_name, wchar_t phone_number[], int year_of_birth, int month_of_birth, int day_of_birth) {

  size_t full_name_len = wcslen(full_name) + 1;
  
  Node *new_node = (Node *)malloc(sizeof(Node) + full_name_len * sizeof(wchar_t));

  if(new_node == NULL) {
    fwprintf(stderr, L"\n-> Memory allocation failed\n");
    free(full_name);
    exit(1); 
  }

  wcscpy(new_node -> full_name, full_name);
  wcsncpy(new_node -> phone_number, phone_number, sizeof(new_node->phone_number) / sizeof(wchar_t) - 1);
  new_node -> phone_number[sizeof(new_node->phone_number) / sizeof(wchar_t) - 1] = L'\0';
  new_node -> year_of_birth = year_of_birth;
  new_node -> month_of_birth = month_of_birth;
  new_node -> day_of_birth = day_of_birth;
  new_node -> next = NULL;

  return new_node;

}

void insert_contact(Node **head, wchar_t *full_name, wchar_t phone_number[], int year_of_birth, int month_of_birth, int day_of_birth) {

  Node *new_node = create_node(full_name, phone_number, year_of_birth, month_of_birth, day_of_birth);

  if(*head == NULL) {
    *head = new_node;
  } else {
    Node *current = *head;
    while(current -> next != NULL) {
      current = current -> next;
    }
    current -> next = new_node;
  }

  wprintf(L"\n\n*** CONTACT DATA ***\n\n");
  wprintf(L"-> Name: %ls;\n", new_node -> full_name);
  wprintf(L"-> Phone Number: %ls;\n", new_node -> phone_number);
  wprintf(L"-> Birthday date: %ld/%ld/%ld.\n", new_node -> month_of_birth, new_node -> day_of_birth, new_node -> year_of_birth);
  wprintf(L"\n-> Registration successfully complete!\n");

}

Node *find_already_existing_node(Node *contact_list[], wchar_t *full_name, wchar_t phone_number[]) {

  Node *aux = *contact_list;

  while (aux != NULL) {
    if (wcscmp(aux -> full_name, full_name) == 0 && wcscmp(aux -> phone_number, phone_number) == 0) {
      return aux;
    }
    aux = aux -> next;
  }

  return NULL;

}

int update_existing_contact(Node *contact_list[], wchar_t *full_name, wchar_t phone_number[], int year_of_birth, int month_of_birth, int day_of_birth) {

  int yes_no = 0;
  Node *node_found = find_already_existing_node(contact_list, full_name, phone_number);

  if(node_found) {
    
    wprintf(L"\n\n-> Contact already registered previously:\n");
    wprintf(L"\n*** CONTACT DATA ***\n\n");
    wprintf(L"-> Name: %ls;\n", node_found -> full_name);
    wprintf(L"-> Phone Number: %ls;\n", node_found -> phone_number);
    wprintf(L"-> Birthday date: %ld/%ld/%ld.\n", node_found -> month_of_birth, node_found -> day_of_birth, node_found -> year_of_birth);

    if(node_found -> year_of_birth != year_of_birth || node_found -> month_of_birth != month_of_birth || node_found -> day_of_birth != day_of_birth) {

      wprintf(L"\n-> Would you want to update this contact's information (1 - Yes / 2 - No)? ");
      wscanf(L" %d", &yes_no);

      while(yes_no < 1 || yes_no > 2) {
        wprintf(L"\n-> Incorrect answer! Choose an option between 1 (Yes) or 2 (No): ");
        wscanf(L" %d", &yes_no);
      }

      if(yes_no == 1) {

        node_found -> year_of_birth = year_of_birth;
        node_found -> month_of_birth = month_of_birth;
        node_found -> day_of_birth = day_of_birth;

        wprintf(L"\n-> Contact updated successfully!\n");

      } else {
        wprintf(L"\n-> Aborting registration operation...\n");
      }

    } else {
      wprintf(L"\n-> Canceling registration operation...\n");
    }

    return 1;

  }

  return 0;

}

int find_contacts_same_phone_number(Node *contact_list[], wchar_t phone_number[]) {

  int count = 0;

  for (size_t i = 0; i < 27; i++) {

    Node *current = contact_list[i];
    
    if(current != NULL) {
      while(current != NULL) {
        if(wcscmp(current -> phone_number, phone_number) == 0) {
          if(count == 0) {
            wprintf(L"\n\n-> There is (are) already (a) contact(s) with this phone number:\n");
            wprintf(L"\n\n*** CONTACT DATA ***\n\n");
            wprintf(L"-> Name: %ls;\n", current -> full_name);
            wprintf(L"-> Phone Number: %ls;\n", current -> phone_number);
            wprintf(L"-> Birthday date: %ld/%ld/%ld.\n", current -> month_of_birth, current -> day_of_birth, current -> year_of_birth);
            current = current -> next;
            count++;
          } else {
            wprintf(L"\n-> Name: %ls;\n", current -> full_name);
            wprintf(L"-> Phone Number: %ls;\n", current -> phone_number);
            wprintf(L"-> Birthday date: %ld/%ld/%ld.\n", current -> month_of_birth, current -> day_of_birth, current -> year_of_birth);
            current = current -> next;
          }
        } else {
          current = current -> next;
        }
      }
    }
  }

  if(count) {
    return 1;
  } else {
    return 0;
  }

}

Node *merge(Node *list1, Node *list2) {

    if (list1 == NULL)
      return list2;
    if (list2 == NULL)
      return list1;

    Node *merged_list = NULL;

    if ((wcscoll(list1 -> full_name, list2 -> full_name) <= 0)) {
      merged_list = list1;
      merged_list -> next = merge(list1 -> next, list2);
    } else {
      merged_list = list2;
      merged_list -> next = merge(list1, list2 -> next);
    }

    return merged_list;
}

void split_list(Node *source, Node **front_ref, Node **back_ref) {
    
    if (source == NULL || source->next == NULL) {
      *front_ref = source;
      *back_ref = NULL;
      return;
    }

    Node *slow = source;
    Node *fast = source->next;

    while (fast != NULL) {
      fast = fast->next;
      if (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
      }
    }

    *front_ref = source;
    *back_ref = slow->next;
    slow->next = NULL;

}

void merge_sort(Node **head_ref) {

    Node *head = *head_ref;
    Node *a;
    Node *b;

    if (head == NULL || head->next == NULL) {
        return;
    }

    split_list(head, &a, &b);

    merge_sort(&a);
    merge_sort(&b);

    *head_ref = merge(a, b);

}

int is_the_list_empty(Node *contact_list[]) {

  for(size_t i = 0; i < 27; i++) {
    if(contact_list[i] != NULL) {
      return 1;
    }
  }

  return 0;

}

int remove_contact(Node **head, wchar_t *full_name, wchar_t phone_number[]) {

  Node *aux = *head, *node_removed, *previous;
  int can_i_remove;

  while(aux != NULL) {

    if((wcscmp(aux -> full_name, full_name) == 0) && (wcscmp(aux -> phone_number, phone_number) == 0)) {

      node_removed = aux;

      can_i_remove = removal_confirmation(node_removed);

      if(can_i_remove == 1) {

        if(aux == *head) {
          *head = node_removed -> next;
        } else {
          aux = previous;
          aux -> next = node_removed -> next;
        }

        wprintf(L"\n-> Contact removed successfully!\n");
        free(node_removed);
        
      } else {
        wprintf(L"\n-> Aborting delete operation...\n");
      }

      return 1;

    } else {
      previous = aux;
      aux = aux -> next;
    }

  }

  return 0;
  
}

int removal_confirmation(Node *node_removed) {

  int yes_no = 0;

  wprintf(L"\n\n*** CONTACT DATA ***\n\n");
  wprintf(L"-> Name: %ls;\n", node_removed -> full_name);
  wprintf(L"-> Phone Number: %ls;\n", node_removed -> phone_number);
  wprintf(L"-> Birthday date: %ld/%ld/%ld.\n", node_removed -> month_of_birth, node_removed -> day_of_birth, node_removed -> year_of_birth);

  wprintf(L"\n-> Are you sure to remove this contact (1 - Yes / 2 - No)? ");
  wscanf(L" %d", &yes_no);

  while(yes_no < 1 || yes_no > 2) {
    wprintf(L"\n-> Incorrect answer! Choose an option between 1 (Yes) or 2 (No): ");
    wscanf(L" %d", &yes_no);
  }

  return yes_no;

}

int find_contacts_same_names(Node **head, wchar_t *full_name) {

  Node *current = *head;

  int count = 0;

  if(current != NULL) {
    while(current != NULL) {
      if(wcscmp(current -> full_name, full_name) == 0) {
        if(count == 0) {
          wprintf(L"\n\n*** CONTACT(S) DATA FOUND ***\n\n");
          wprintf(L"-> Name: %ls;\n", current -> full_name);
          wprintf(L"-> Phone Number: %ls;\n", current -> phone_number);
          wprintf(L"-> Birthday date: %ld/%ld/%ld.\n", current -> month_of_birth, current -> day_of_birth, current -> year_of_birth);
          current = current -> next;
          count++;
        } else {
          wprintf(L"\n-> Name: %ls;\n", current -> full_name);
          wprintf(L"-> Phone Number: %ls;\n", current -> phone_number);
          wprintf(L"-> Birthday date: %ld/%ld/%ld.\n", current -> month_of_birth, current -> day_of_birth, current -> year_of_birth);
          current = current -> next;
        }
      } else {
        current = current -> next;
      }

    }

  }
  
  if(count) {
    wprintf(L"\n-----------------------------\n");
    return 1;
  } else {
    return 0;
  }

}

void print_list(Node *contact_list[]) {

  wprintf(L"\n\n*** CONTACT LIST ***\n\n");
  for (size_t i = 0; i < 27; i++) {

    Node *current = contact_list[i];
    
    if(current != NULL) {
      if(i <= 25) {
        wprintf(L"%lc:\n", 'A' + i);
      } else {
        wprintf(L"NON-STANDARD NAMES:\n\n");
      }
      while(current != NULL) {
        wprintf(L"\n-> Name: %ls;\n", current -> full_name);
        wprintf(L"-> Phone Number: %ls;\n", current -> phone_number);
        wprintf(L"-> Birthday date: %ld/%ld/%ld.\n", current -> month_of_birth, current -> day_of_birth, current -> year_of_birth);
        current = current -> next;
      }
      wprintf(L"\n-----------------------------\n");
    }
  }
}

void free_list(Node *head) {

  Node *current = head, *next;

  while(current != NULL) {
    next = current -> next;
    free(current);
    current = next;
  }

}