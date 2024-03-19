#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

int main() {

    Product *product_list = NULL, *search_node;
    int option, code, amount, prev_code;
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

                printf("\n*** PROD INFO ***\n\n");
                printf("1) Product code: ");
                scanf("%u", &code);

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

                printf("\n*** PROD INFO ***\n\n");
                printf("1) Product code: ");
                scanf("%u", &code);

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

                printf("\n*** PROD INFO ***\n\n");
                printf("1) Product code: ");
                scanf("%d", &code);
                printf("2) Product name: ");
                scanf(" %[^\n]", name);
                printf("3) Amount: ");
                scanf("%d", &amount);

                printf("\n-> Enter a code of reference to make it possible to insert the new product after this code: ");
                scanf("%d", &prev_code);

                insert_at_the_middle(&product_list, code, name, amount, prev_code);

                break;

            case 4:

                printf("\n*** PROD INFO ***\n\n");
                printf("1) Product code: ");
                scanf("%d", &code);
                printf("2) Product name: ");
                scanf(" %[^\n]", name);
                printf("3) Amount: ");
                scanf("%d", &amount);

                insert_sorted(&product_list, code, name, amount);

                break;

            case 5:

                printf("\n- Enter the code to be removed: ");
                scanf("%d", &code);
                
                remove_element(&product_list, code);

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