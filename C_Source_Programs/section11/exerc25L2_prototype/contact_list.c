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

void insert_contact(Node** head, wchar_t* full_name, wchar_t phone_number[], int year_of_birth, int month_of_birth, int day_of_birth) {

  Node* new_node = create_node(full_name, phone_number, year_of_birth, month_of_birth, day_of_birth);

  if(*head == NULL) {
    *head = new_node;
  } else {
    Node* current = *head;
    while(current -> next != NULL) {
      current = current -> next;
    }
    current -> next = new_node;
  }

  wprintf(L"\n\n*** CONTACT DATA ***\n\n");
  wprintf(L"-> Name: %ls;\n", new_node -> full_name);
  wprintf(L"-> Phone Number: %ls;\n", new_node -> phone_number);
  wprintf(L"-> Birthday date: %ld/%ld/%ld.\n", new_node -> month_of_birth, new_node -> day_of_birth, new_node -> year_of_birth);
  wprintf(L"\n\n-> Registration successfully complete!\n\n");

}

Node* create_node(wchar_t* full_name, wchar_t phone_number[], int year_of_birth, int month_of_birth, int day_of_birth) {

  size_t full_name_len = wcslen(full_name) + 1;
  
  Node* new_node = (Node*)malloc(sizeof(Node) + full_name_len * sizeof(wchar_t));

  if(new_node == NULL) {
    fwprintf(stderr, L"Memory allocation failed\n");
    free(full_name);
    exit(1);
  }

  wcscpy(new_node -> full_name, full_name);
  wcsncpy(new_node->phone_number, phone_number, sizeof(new_node->phone_number) / sizeof(wchar_t) - 1);
  new_node->phone_number[sizeof(new_node->phone_number) / sizeof(wchar_t) - 1] = L'\0';
  new_node -> year_of_birth = year_of_birth;
  new_node -> month_of_birth = month_of_birth;
  new_node -> day_of_birth = day_of_birth;
  new_node -> next = NULL;

  return new_node;

}

Node* merge(Node* list1, Node* list2) {

    if (list1 == NULL)
      return list2;
    if (list2 == NULL)
      return list1;

    Node* merged_list = NULL;

    if ((wcscoll(list1 -> full_name, list2 -> full_name) <= 0)) {
      merged_list = list1;
      merged_list -> next = merge(list1 -> next, list2);
    } else {
      merged_list = list2;
      merged_list -> next = merge(list1, list2 -> next);
    }

    return merged_list;
}

void split_list(Node* source, Node** front_ref, Node** back_ref) {
    
    if (source == NULL || source->next == NULL) {
      *front_ref = source;
      *back_ref = NULL;
      return;
    }

    Node* slow = source;
    Node* fast = source->next;

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

void merge_sort(Node** head_ref) {

    Node* head = *head_ref;
    Node* a;
    Node* b;

    if (head == NULL || head->next == NULL) {
        return;
    }

    split_list(head, &a, &b);

    merge_sort(&a);
    merge_sort(&b);

    *head_ref = merge(a, b);

}

void print_list(Node* contact_list[]) {

  wprintf(L"\n\n*** CONTACT LIST ***\n\n");
  for (size_t i = 0; i < 27; i++) {

    Node* current = contact_list[i];
    
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
      wprintf(L"\n-----------------------------\n\n");
    }
  }
}

void free_list(Node* head) {

  Node *current = head, *next;

  while(current != NULL) {
    next = current -> next;
    free(current);
    current = next;
  }

}