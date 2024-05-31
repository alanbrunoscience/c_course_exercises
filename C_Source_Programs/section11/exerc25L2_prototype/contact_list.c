#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <ctype.h>
#include <wctype.h>
#include <locale.h>
#include "contact_list.h"

#define MAX_NAME_LENGTH 40

void initialize_lists(Node* contact_list[]) {
  for (size_t i = 0; i < 27; i++) {
    contact_list[i] = NULL;
  }
}

void format_name_variable(wchar_t name[], size_t* total_length) {

  wchar_t str[MAX_NAME_LENGTH];
  wcscpy(str, name);
  const wchar_t delim[] = L" ,.!";
  wchar_t* saveptr = NULL;
  wchar_t* token = wcstok(str, delim, &saveptr);
  
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
    exit(1);
  }

  (*full_name)[0] = L'\0';
  wcscpy(*full_name, first_name);
  wcscat(*full_name, L" ");
  wcscat(*full_name, last_name);

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

int get_index(wchar_t full_name[]) {

  wchar_t first_letter = full_name[0];

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

void insert_contact(Node** head, wchar_t* full_name) {

  Node* new_node = create_node(full_name);

  if(*head == NULL) {
    *head = new_node;
  } else {
    Node* current = *head;
    while(current -> next != NULL) {
      current = current -> next;
    }
    current -> next = new_node;
  }

}

Node* create_node(wchar_t* full_name) {

  size_t full_name_len = wcslen(full_name) + 1;
  
  Node* new_node = (Node*)malloc(sizeof(Node) + full_name_len * sizeof(wchar_t));

  if(new_node == NULL) {
    fwprintf(stderr, L"Memory allocation failed\n");
    free(full_name);
    exit(1);
  }

  wcscpy(new_node -> full_name, full_name);
  new_node -> next = NULL;

  return new_node;

}

void print_list(Node* contact_list[]) {

  wprintf(L"\n*** CONTACT LIST ***");
  for (size_t i = 0; i < 27; i++) {

    Node* current = contact_list[i];
    
    if(current != NULL) {
      if(i <= 25) {
        wprintf(L"\n\n%lc:\n\n", 'A' + i);
      } else {
        wprintf(L"\n\nNON-STANDARD NAMES:\n\n");
      }
      while(current != NULL) {
        wprintf(L"- %ls\n", current -> full_name);
        current = current -> next;
      }
      wprintf(L"\n-----------------------------");
    }
  }
}

void free_list(Node* head) {

  Node* current = head;

  while(current != NULL) {
    Node* next = current -> next;
    free(current);
    current = next;
  }

}