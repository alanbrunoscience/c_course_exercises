#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

int update_elem_dif_names(Product *current, char name[], int quantity) {

    int yes_no;

    printf("\n-> The names are different! Do you want to overwrite this product? (1 - Yes / 2 - No): ");
    scanf("%d", &yes_no);

    while(yes_no != 1 && yes_no != 2) {
        printf("\n-> Invalid option! Choose 1 or 2, please: ");
        scanf("%d", &yes_no);
    }

    if(yes_no == 1) {

        strncpy(current -> name, name, sizeof(current -> name) - 1); // Copy name
        current -> name[sizeof(current -> name) - 1] = '\0'; // Ensure null-termination
        current -> quantity = quantity;

        printf("\n-> Updating item information...\n");

        return 0;

    } else {

        printf("\n-> Discarding changes...\n");

        return 1;

    }

}

int update_elem_same_names(Product *current, int quantity) {

    int yes_no, quantity_update;

    printf("\n-> The names are the same! Do you want to update item information? (1 - Yes / 2 - No): ");
    scanf("%d", &yes_no);

    while(yes_no != 1 && yes_no != 2) {
        printf("\n-> Invalid option! Choose 1 or 2, please: ");
        scanf("%d", &yes_no);
    }

    if(yes_no == 1) {
        printf("\n-> Would you like to increase the quantity or only update it? Press '1' to increment the quantity or '2' to only update it: ");
        scanf("%d", &quantity_update);

        while(quantity_update != 1 && quantity_update != 2) {
            printf("\n-> Invalid option! Choose 1 or 2, please: ");
            scanf("%d", &quantity_update);
        }

        if(quantity_update == 1) {
            current -> quantity = current -> quantity + quantity;
            printf("\n-> Incrementing the quantity...\n");
            return 0;
        } else {
            printf("\n-> Overwriting the quantity to the new value inserted...\n");
            current -> quantity = quantity;
            return 0;
        }

    } else {

        printf("\n-> Discarding changes...\n");

        return 1;
    }

}

int update_existing_item(Product **product_list, int code, char name[], int quantity) {

    Product *current = *product_list;

    while (current != NULL) {
        if (current -> code == code) {
            if (strcmp(current -> name, name) != 0) {

                int result = update_elem_dif_names(current, name, quantity);

                return result;

            } else {

                int result = update_elem_same_names(current, quantity);

                return result;
                
            }
        }

        current = current -> next;

    }

    return 2;

}

void insert_at_the_beginning(Product **product_list, int code, char name[], int quantity) {

    int func_return = update_existing_item(product_list, code, name, quantity);

    if(func_return == 2) {
        // Create a new node
        Product *new_product = (Product *)malloc(sizeof(Product));

        if(new_product == NULL) {
            puts("\n-> Memory allocation failed.");
            return;
        }

        // Fill in the details for the new node
        new_product -> code = code;
        strncpy(new_product -> name, name, sizeof(new_product -> name) - 1); // Copy name
        new_product -> name[sizeof(new_product -> name) - 1] = '\0'; // Ensure null-termination
        new_product -> quantity = quantity;

        if(*product_list) {
            new_product -> next = *product_list;
            *product_list = new_product;    
        } else {
            new_product -> next = NULL;
            *product_list = new_product;
        }

    }

}

void insert_at_the_end(Product **product_list, int code, char name[], int quantity) {

    int func_return = update_existing_item(product_list, code, name, quantity);

    if(func_return == 2) {

        Product *aux, *new_product = (Product *)malloc(sizeof(Product));

        if(new_product == NULL) {
            puts("\n-> Memory allocation failed.");
            return;
        }

        new_product -> code = code;
        strncpy(new_product -> name, name, sizeof(new_product -> name) - 1);
        new_product -> name[sizeof(new_product -> name) - 1] = '\0';
        new_product -> quantity = quantity;

        new_product -> next = NULL;

        if(*product_list) {
            aux = *product_list;
            while(aux -> next) {
                aux = aux -> next;
            }
            aux -> next = new_product;
        } else {
            *product_list = new_product;
        }

    }

}

int validate_code_existence(Product **product_list, int ref_code) {

    Product *current = *product_list;
    int found_element = 0;

    while(current != NULL) {
        if (current -> code == ref_code) {
            found_element++;
        }
        current = current -> next;
    }

    if(found_element) {
        printf("\n-> Code found successfully!\n");
        return 0;
    } else {
        printf("\n\n-> Code inexistent on the list!\n");
        return 1;
    }

}

void insert_at_the_middle(Product **product_list, int code, char name[], int quantity, int ref_code) {

    int func_return = update_existing_item(product_list, code, name, quantity);

    if(func_return == 2) {

        Product *aux = *product_list, *new_product = (Product *)malloc(sizeof(Product));

        if(new_product == NULL) {
            puts("\n-> Memory allocation failed.");
            return;
        }

        new_product -> code = code;
        strncpy(new_product -> name, name, sizeof(new_product -> name) - 1);
        new_product -> name[sizeof(new_product -> name) - 1] = '\0';
        new_product -> quantity = quantity;

        while(aux -> code != ref_code) {
            aux = aux -> next;
        }

        new_product -> next = aux -> next;
        aux -> next = new_product;
        
    }

}

void insert_sorted(Product **product_list, int code, char name[], int quantity) {

    int func_return = update_existing_item(product_list, code, name, quantity);

    if(func_return == 2) {
    
        Product *aux, *new_product = (Product *)malloc(sizeof(Product));

        if(new_product == NULL) {
            puts("\n-> Memory allocation failed.");
            return;
        }

        new_product -> code = code;
        strncpy(new_product -> name, name, sizeof(new_product -> name) - 1);
        new_product -> name[sizeof(new_product -> name) - 1] = '\0';
        new_product -> quantity = quantity;

        if(*product_list == NULL) {

            new_product -> next = NULL;
            *product_list = new_product;

        }
        else if(new_product -> code < (*product_list) -> code) {

            new_product -> next = *product_list;
            *product_list = new_product;

        } else {

            aux = *product_list;

            while(aux -> next && new_product -> code > aux -> next -> code) {
                aux = aux -> next;
            }

            new_product -> next = aux -> next;
            aux -> next = new_product;

        }
    }

}

void remove_element(Product **product_list, int code, int quantity) {

    Product *aux, *node_removed;

    if((*product_list) -> code == code) {
        
        node_removed = *product_list;

        if(node_removed -> quantity == quantity) {
            *product_list = node_removed -> next;
            printf("\n-> Element completely removed - Code %d.\n", node_removed -> code);
            free(node_removed);
        } else {
            node_removed -> quantity = node_removed -> quantity - quantity;
            printf("\n-> Element's quantity updated to %d.\n", node_removed -> quantity);
        }

    } else {

        aux = *product_list;

        while(aux -> next -> code != code) {
            aux = aux -> next;
        }

        node_removed = aux -> next;

        if(node_removed -> quantity == quantity) {
            aux -> next = node_removed -> next;
            printf("\n-> Element completely removed - Code %d.\n", node_removed -> code);
            free(node_removed);
        } else {
            node_removed -> quantity = node_removed -> quantity - quantity;
            printf("\n-> Element's quantity updated to %d.\n", node_removed -> quantity);
        }

    }

}

Product* search_element(Product **product_list, int code) {

    Product *aux, *node_found = NULL;

    aux = *product_list;

    while(aux && aux -> code != code) {
        aux = aux -> next;
    }

    if(aux) {
        node_found = aux;
    }

    return node_found;

}

void print_list(Product *product_list) {

    
    printf("\n*** PRODUCTS ***\n\n");

    while(product_list) {

        printf("- Code: %d\n", product_list -> code);
        printf("- Name: %s\n", product_list -> name);
        printf("- Total quantity in stock: %d\n\n", product_list -> quantity);

        product_list = product_list -> next;

    }
    
}

void free_memory(Product *product_list) {

    Product *current = product_list, *next;

    while (current != NULL) {
        next = current -> next;
        free(current);
        current = next;
    }
}