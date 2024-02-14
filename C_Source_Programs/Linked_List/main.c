#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

int main() {

    Product *product_list = NULL;
    int option, code, amount = 1, prev_code;
    char name[40];

    do {
        printf("*** OPTIONS MENU ***\n\n");
        printf("1 - Insert product at the beginning;\n");
        printf("2 - Insert product at the end;\n");
        printf("3 - Insert product at the middle;\n");
        printf("4 - Insert sorted;\n");
        printf("5 - Remove element;\n");
        printf("6 - Print list;\n\n-> ");
        scanf("%d", &option);

        switch(option) {
            case 1:

                printf("\n*** PROD INFO ***\n\n");
                printf("1) Product code: ");
                scanf("%d", &code);
                printf("2) Product name: ");
                scanf(" %[^\n]", name);
                printf("3) Amount: ");
                scanf("%d", &amount);

                insert_at_the_beginning(&product_list, code, name, amount);

                break;

            case 2:

                printf("\n*** PROD INFO ***\n\n");
                printf("1) Product code: ");
                scanf("%d", &code);
                printf("2) Product name: ");
                scanf(" %[^\n]", name);
                printf("3) Amount: ");
                scanf("%d", &amount);

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

                print_list(product_list);

                break;

            default:
                if(option != 0) {
                    printf("\n-> Invalid option!\n");
                }

        }

        printf("\n\n");

    } while(option != 0);

    free_memory(product_list);

    return 0;

}