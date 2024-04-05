#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

int main() {

    Product *product_list = NULL, *search_node;
    int option, code, amount, ref_code;
    char name[40];

    do {
        printf("*** OPTIONS MENU ***\n\n");
        printf("1 - Insert product at the beginning;\n");
        printf("2 - Insert product at the end;\n");
        printf("3 - Insert product at the middle;\n");
        printf("4 - Insert sorted;\n");
        printf("5 - Remove element;\n");
        printf("6 - Search element;\n");
        printf("7 - Print list;\n");
        printf("8 - Finish the program.\n\n-> ");
        scanf("%d", &option);

        switch(option) {
            
            case 1:

                printf("\n*** PRODUCT INFO ***\n\n");
                printf("1) Product code: ");
                scanf("%d", &code);

                while(code < 0) {
                    printf("\n-> Invalid code! Enter a code greater or equal to 0: ");
                    scanf("%d", &code);
                }

                printf("\n2) Product name: ");
                scanf(" %[^\n]", name);
                printf("\n3) Amount: ");
                scanf("%d", &amount);

                while(amount <= 0) {
                    printf("\n-> Invalid amount! Enter an amount greater than 0: ");
                    scanf("%d", &amount);
                }

                insert_at_the_beginning(&product_list, code, name, amount);

                break;

            case 2:

                printf("\n*** PRODUCT INFO ***\n\n");
                printf("1) Product code: ");
                scanf("%d", &code);

                while(code < 0) {
                    printf("\n-> Invalid code! Enter a code greater or equal to 0: ");
                    scanf("%d", &code);
                }

                printf("\n2) Product name: ");
                scanf(" %[^\n]", name);
                printf("\n3) Amount: ");
                scanf("%d", &amount);

                while(amount <= 0) {
                    printf("\n-> Invalid amount! Enter an amount greater than 0: ");
                    scanf("%d", &amount);
                }

                insert_at_the_end(&product_list, code, name, amount);

                break;

            case 3:

                if(product_list == NULL) {
                    printf("\n\n-> The product's list is empty! Firstly, insert an element on the list...\n");
                    break;
                }

                printf("\n*** REFERENCE CODE ***\n\n");
            
                printf("1) Enter a code of reference to make it possible to insert the new product after this code: ");
                scanf("%d", &ref_code);

                while(ref_code < 0) {
                    printf("\n-> Invalid code! Enter a code greater or equal to 0: ");
                    scanf("%d", &ref_code);
                }

                int func_return = validate_code_existence(&product_list, ref_code);

                if(func_return == 0) {
                    
                    printf("\n*** PRODUCT INFO ***\n\n");
                    printf("1) Product code: ");
                    scanf("%d", &code);

                    while(code < 0) {
                        printf("\n-> Invalid code! Enter a code greater or equal to 0: ");
                        scanf("%d", &code);
                    }

                    printf("\n2) Product name: ");
                    scanf(" %[^\n]", name);
                    printf("\n3) Amount: ");
                    scanf("%d", &amount);

                    while(amount <= 0) {
                        printf("\n-> Invalid amount! Enter an amount greater than 0: ");
                        scanf("%d", &amount);
                    }

                    insert_at_the_middle(&product_list, code, name, amount, ref_code);

                }           

                break;

            case 4:

                printf("\n*** PRODUCT INFO ***\n\n");
                printf("1) Product code: ");
                scanf("%d", &code);

                while(code < 0) {
                    printf("\n-> Invalid code! Enter a code greater or equal to 0: ");
                    scanf("%d", &code);
                }

                printf("\n2) Product name: ");
                scanf(" %[^\n]", name);
                printf("\n3) Amount: ");
                scanf("%d", &amount);

                while(amount <= 0) {
                    printf("\n-> Invalid amount! Enter an amount greater than 0: ");
                    scanf("%d", &amount);
                }

                insert_sorted(&product_list, code, name, amount);

                break;

            case 5:

                if(product_list == NULL) {
                    printf("\n-> The product's list is empty!\n");
                    break;
                }

                printf("\n*** CODE TO BE REMOVED ***\n\n");
            
                printf("1) Enter the code to be removed: ");
                scanf("%d", &code);

                while(code < 0) {
                    printf("\n-> Invalid code! Enter a code greater or equal to 0: ");
                    scanf("%d", &code);
                }

                int code_verification = validate_code_existence(&product_list, code);

                if(code_verification == 0) {
                    
                    search_node = search_element(&product_list, code);

                    printf("\n*** ELEMENT INFO ***\n\n");
                    printf("-> Code: %d;\n", search_node -> code);
                    printf("-> Name: %s;\n", search_node -> name);
                    printf("-> Amount: %d;\n", search_node -> amount);

                    printf("\n2) How many quantities of this product would you like to remove? ");
                    scanf("%d", &amount);

                    while(amount <= 0 || amount > search_node -> amount) {
                        printf("\n-> Invalid amount! Enter an amount greater than 0 and less than or equal to %d: ", search_node -> amount);
                        scanf("%d", &amount);
                    }

                    remove_element(&product_list, code, amount);
                }

                break;
            
            case 6:

                printf("\n- Enter the code to be searched: ");
                scanf("%d", &code);

                search_node = search_element(&product_list, code);
                
                if(search_node) {
                    printf("\n*** ELEMENT FOUND INFO ***\n\n");
                    printf("-> Code: %d;\n", search_node -> code);
                    printf("-> Name: %s;\n", search_node -> name);
                    printf("-> Amount: %d;\n", search_node -> amount);
                } else {
                    printf("\n-> Element not found!\n");
                }

                break;

            case 7:

                print_list(product_list);

                break;

            default:

                if(option != 8) {
                    printf("\n-> Invalid option!\n");
                }

        }

        printf("\n\n");

    } while(option != 8);

    printf("Finishing the program...\n");

    free_memory(product_list);

    return 0;

}