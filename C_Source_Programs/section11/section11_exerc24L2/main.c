#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "products_list.h"

int main() {

    Available_prod *av_prod_list = NULL, *search_node_av_list;
    Unavailable_prod *unav_prod_list = NULL, *search_node_unav_list;
    int option, code, quantity;
    char name[40];

    do {

        printf("*** HOME PANTRY ***\n\n");
        printf("1 - Insert product;\n");
        printf("2 - Remove product;\n");
        printf("3 - Restore a product deleted;\n");
        printf("4 - Remove a product permanently;\n");
        printf("5 - Search product;\n");
        printf("6 - Update product data;\n");
        printf("7 - Print available products report;\n");
        printf("8 - Print unavailable products report;\n");
        printf("9 - Finish the program.\n\n-> ");
        scanf("%d", &option);

        switch (option) {

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
                printf("\n3) Quantity: ");
                scanf("%d", &quantity);

                while(quantity <= 0) {
                    printf("\n-> Invalid quantity! Enter a quantity greater than 0: ");
                    scanf("%d", &quantity);
                }

                int funct_return_av_list = check_item_existence_av_prod_list(&av_prod_list, code, name, quantity);

                int funct_return_unav_list = check_item_existence_unav_prod_list(&av_prod_list, &unav_prod_list, code, name, quantity);

                if(funct_return_av_list == 2 && funct_return_unav_list == 2) {
                    insert_in_available_prod_list(&av_prod_list, code, name, quantity);
                }

                break;

            case 2:

                if(av_prod_list == NULL) {
                    printf("\n-> The available products list is empty!\n");
                    break;
                }

                printf("\n*** CODE TO BE REMOVED ***\n\n");
            
                printf("1) Enter the code to be removed: ");
                scanf("%d", &code);

                while(code < 0) {
                    printf("\n-> Invalid code! Enter a code greater or equal to 0: ");
                    scanf("%d", &code);
                }

                if(validate_code_existence_av_list(&av_prod_list, code) == 0) {

                    printf("\n-> Code found successfully!\n");
                    
                    search_node_av_list = search_available_product(&av_prod_list, code);

                    printf("\n*** ELEMENT INFO ***\n\n");
                    printf("-> Code: %d\n", search_node_av_list -> code);
                    printf("-> Name: %s\n", search_node_av_list -> name);
                    printf("-> Quantity: %d\n", search_node_av_list -> quantity);

                    printf("\n2) How many quantities of this product would you like to remove? ");
                    scanf("%d", &quantity);

                    while(quantity <= 0 || quantity > search_node_av_list -> quantity) {
                        printf("\n-> Invalid quantity! Enter a quantity greater than 0 and less than or equal to %d: ", search_node_av_list -> quantity);
                        scanf("%d", &quantity);
                    }

                    remove_from_available_listI(&av_prod_list, &unav_prod_list, code, quantity);

                } else {

                    printf("\n-> Code inexistent on the list!\n");

                }

                break;

            case 3:

                if(unav_prod_list == NULL) {
                    printf("\n-> The unavailable products list is empty!\n");
                    break;
                }

                printf("\n*** CODE TO BE RESTORED ***\n\n");
            
                printf("1) Enter the code to be restored: ");
                scanf("%d", &code);

                while(code < 0) {
                    printf("\n-> Invalid code! Enter a code greater or equal to 0: ");
                    scanf("%d", &code);
                }

                if(validate_code_existence_unav_list(&unav_prod_list, code) == 0) {

                    printf("\n-> Code found successfully!\n");

                    search_node_unav_list = search_unavailable_product(&unav_prod_list, code);

                    printf("\n*** ELEMENT INFO ***\n\n");
                    printf("-> Code: %d\n", search_node_unav_list -> code);
                    printf("-> Name: %s\n", search_node_unav_list -> name);
                    printf("-> Quantity: %d\n", search_node_unav_list -> quantity);

                    printf("\n2) Enter the new quantity of the product: ");
                    scanf("%d", &quantity);

                    while(quantity <= 0) {
                        printf("\n-> Invalid quantity! Enter a quantity greater than 0: ");
                        scanf("%d", &quantity);
                    }

                    insert_in_available_prod_list(&av_prod_list, code, (search_node_unav_list -> name), quantity);
                    remove_from_unavailable_list(&unav_prod_list, code);

                    printf("\n-> Code restored successfully!\n");
                    
                } else {

                    printf("\n-> Code inexistent on the list!\n");

                }

                break;

            case 4:

                if(av_prod_list == NULL && unav_prod_list == NULL) {
                    printf("\n-> The available and unavailable product lists are empty!\n");
                    break;
                }

                printf("\n*** CODE TO BE DELETED PERMANENTLY ***\n\n");
            
                printf("1) Enter the code to be deleted permanently: ");
                scanf("%d", &code);

                while(code < 0) {
                    printf("\n-> Invalid code! Enter a code greater or equal to 0: ");
                    scanf("%d", &code);
                }

                if(validate_code_existence_av_list(&av_prod_list, code) == 0) {

                    printf("\n-> Code found successfully!\n");

                    search_node_av_list = search_available_product(&av_prod_list, code);

                    printf("\n*** ELEMENT INFO ***\n\n");
                    printf("-> Code: %d\n", search_node_av_list -> code);
                    printf("-> Name: %s\n", search_node_av_list -> name);
                    printf("-> Quantity: %d\n", search_node_av_list -> quantity);

                    remove_av_prod_permanently(&av_prod_list, code);

                } else if(validate_code_existence_unav_list(&unav_prod_list, code) == 0) {

                    printf("\n-> Code found successfully!\n");

                    search_node_unav_list = search_unavailable_product(&unav_prod_list, code);

                    printf("\n*** ELEMENT INFO ***\n\n");
                    printf("-> Code: %d\n", search_node_unav_list -> code);
                    printf("-> Name: %s\n", search_node_unav_list -> name);
                    printf("-> Quantity: %d\n", search_node_unav_list -> quantity);

                    remove_unav_prod_permanently(&unav_prod_list, code);

                } else {

                    printf("\n-> Code inexistent on the lists!\n");

                }

                break;

            case 5:

                if(av_prod_list == NULL) {
                    printf("\n-> The available products list is empty!\n");
                    break;
                }

                printf("\n- Enter the code to be searched: ");
                scanf("%d", &code);

                search_node_av_list = search_available_product(&av_prod_list, code);
                
                if(search_node_av_list) {
                    printf("\n*** ELEMENT FOUND INFO ***\n\n");
                    printf("-> Code: %d\n", search_node_av_list -> code);
                    printf("-> Name: %s\n", search_node_av_list -> name);
                    printf("-> Quantity: %d\n", search_node_av_list -> quantity);
                } else {
                    printf("\n-> Element not found!\n");
                }

                break;

            case 6:

                if(av_prod_list == NULL) {
                    printf("\n-> The available products list is empty!\n");
                    break;
                }

                printf("\n*** CODE TO BE UPDATED ***\n\n");
            
                printf("1) Enter the code to be updated: ");
                scanf("%d", &code);

                while(code < 0) {
                    printf("\n-> Invalid code! Enter a code greater or equal to 0: ");
                    scanf("%d", &code);
                }

                if(validate_code_existence_av_list(&av_prod_list, code) == 0) {

                    printf("\n-> Code found successfully!\n");

                    search_node_av_list = search_available_product(&av_prod_list, code);

                    printf("\n\n*** ELEMENT INFO ***\n\n");
                    printf("-> Code: %d\n", search_node_av_list -> code);
                    printf("-> Name: %s\n", search_node_av_list -> name);
                    printf("-> Quantity: %d\n", search_node_av_list -> quantity);

                    printf("\n\n*** NEW PRODUCT DATA ***\n\n");
                    printf("1) Product name: ");
                    scanf(" %[^\n]", name);
                    printf("\n2) Quantity: ");
                    scanf("%d", &quantity);

                    while(quantity <= 0) {
                        printf("\n-> Invalid quantity! Enter a quantity greater than 0: ");
                        scanf("%d", &quantity);
                    }

                    check_item_existence_av_prod_list(&av_prod_list, code, name, quantity);

                } else {

                    printf("\n-> Code inexistent on the list!\n");

                }

                break;

            case 7:

                if(av_prod_list == NULL) {
                    printf("\n-> The available products list is empty!\n");
                    break;
                }

                char filename_av_prod[] = "available_products.bin";

                generate_available_prod_report(av_prod_list, unav_prod_list, filename_av_prod);

                printf("\n");

                print_av_prod_list(av_prod_list, unav_prod_list, filename_av_prod);

                remove("available_products.bin");

                break;

            case 8:

                if(unav_prod_list == NULL) {
                    printf("\n-> The unavailable products list is empty!\n");
                    break;
                }

                char filename_unav_prod[] = "unavailable_products.bin";

                generate_unavailable_prod_report(av_prod_list, unav_prod_list, filename_unav_prod);

                printf("\n");

                print_unav_prod_list(av_prod_list, unav_prod_list, filename_unav_prod);

                remove("unavailable_products.bin");

                break;
            
            default:
                
                if(option != 9) {
                    printf("\n-> Invalid option!\n");
                }

                break;
        }

        printf("\n\n");

    } while(option != 9);

    printf("Finishing the program...\n");

    free_memory(av_prod_list, unav_prod_list);

    return 0;

}