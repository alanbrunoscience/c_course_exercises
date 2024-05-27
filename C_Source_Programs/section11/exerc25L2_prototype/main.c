#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

#define MAX_NAME_LENGTH 40

// Define the structure for a node in the linked list
// typedef struct Node {
//     struct Node* next;
//     wchar_t full_name[];
// } Node;

// void initialize_lists(Node* contact_list[]);
int format_fullname_variable(wchar_t **full_name, wchar_t first_name[], wchar_t last_name[]);
// int get_index(Node* contact_list[], char full_name[]);
// void insert_contacts_list(Node **contact_list, char full_name[]);

int main() {

    setlocale(LC_ALL, "");

    int option;
    wchar_t first_name[MAX_NAME_LENGTH];
    wchar_t last_name[MAX_NAME_LENGTH];
    wchar_t *full_name = NULL;
    // Node* contact_list[26];

    // initialize_lists(contact_list);

    do {

        printf("*** OPTIONS MENU ***\n\n");
        printf("1 - Insert contact;\n");
        printf("2 - Print contact list;\n");
        printf("3 - Finish the program.\n\n-> ");
        scanf("%d", &option);

        switch (option) {

        case 1:

            wprintf(L"\n*** CONTACT INFO ***\n\n");
            wprintf(L"1) First Name: ");
            fwscanf(stdin, L" %ls[^\n]", first_name);

            wprintf(L"2) Last Name: ");
            fwscanf(stdin, L" %ls[^\n]", last_name);

            format_fullname_variable(&full_name, first_name, last_name);

            // // Allocate and initialize each Node
            // for (int i = 0; i < 26; i++) {
            //     contact_list[i] = malloc(sizeof(Node));
            //     contact_list[i]->value = 'A' + i;  // Initialize the value field with the corresponding letter
            // }

            // int index_array = full_name[0];

            // insert_contacts_list(&contact_list[], full_name);

            free(full_name);

            break;

        case 2:

            // print_list();

            break;

        default:

            if (option != 3) {
                printf("\n-> Invalid option!\n");
            }

        }

        printf("\n\n");

    } while (option != 3);

    printf("Finishing the program...\n");

    return 0;

}

// void initialize_lists(Node* contact_list[]) {
//     for(int i = 0; i < 26; i++) {
//         contact_list[i] = NULL;
//     }
// }

// int format_fullname_variable(wchar_t **full_name, wchar_t first_name[], wchar_t last_name[]) {

//     first_name[0] = towupper(first_name[0]);
//     last_name[0] = towupper(last_name[0]);

//     for(size_t i = 1; first_name[i] != '\0'; i++) {
        
//     }

//     if(first_name[wcslen(first_name) - 1] == ' ') {

//        // Calculate total characters including space and null terminator
//         size_t total_characters = wcslen(first_name) + wcslen(last_name) + 2;

//         *full_name = (wchar_t *)malloc(total_characters * sizeof(wchar_t));

//         if (*full_name == NULL)
//         {
//             fputws(L"\n-> Memory allocation failed!", stderr);
//             free(full_name);
//             return 1;
//         }

//         // Always add a space between names
//         wcscpy(*full_name, first_name);
//         wcscat(*full_name, last_name);

//         // Set the null terminator explicitly
//         (*full_name)[total_characters - 1] = L'\0';
    
//     } else {

//         // Calculate total characters including space and null terminator
//         size_t total_characters = wcslen(first_name) + wcslen(last_name) + 3;

//         *full_name = (wchar_t *)malloc(total_characters * sizeof(wchar_t));

//         if (*full_name == NULL)
//         {
//             fputws(L"\n-> Memory allocation failed!", stderr);
//             free(full_name);
//             return 1;
//         }

//         // Always add a space between names
//         wcscpy(*full_name, first_name);
//         wcscat(*full_name, L" ");
//         wcscat(*full_name, last_name);

//         // Set the null terminator explicitly
//         (*full_name)[total_characters - 1] = L'\0';

//     }

//     return 0;

// }

// int get_index(Node* contact_list[], char full_name[]) {

//     char first_letter = toupper(full_name[0]);

//     if(strcmp(first_letter, "Ä") == 0 || strcmp(first_letter, "Á") == 0 || strcmp(first_letter, "À") == 0 || strcmp(first_letter, "Â") == 0 || strcmp(first_letter, "Ã") == 0) {
//         return 0;
//     } else if() {
//         return 2;
//     } else if() {
//         return 4;
//     } else if() {
//         return 8;
//     } else if() {
//         return 13;
//     } else if() {
//         return 14;
//     } else if() {
//         return 20;
//     } else if() {
//         return 24;
//     }

// }

// void insert_contacts_list(Node **contact_list, char full_name[]) {

//     Node *aux, *new_contact = malloc(sizeof(Node));

//     if(new_contact == NULL) {
//         puts("\n-> Memory allocation failed.");
//         return;
//     }

//     strncpy(new_contact -> full_name, full_name, sizeof(new_contact -> full_name) - 1);
//     new_contact -> full_name[sizeof(new_contact -> full_name) - 1] = '\0';

//     new_contact -> next = NULL;

//     if(*contact_list) {
//         aux = *contact_list;
//         while(aux -> next) {
//             aux = aux -> next;
//         }
//         aux -> next = new_contact;
//     } else {
//         *contact_list = new_contact;
//     }

// }