#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

int insertion_validation(Product **product_list, int code, char name[], int amount) {

    Product *current = *product_list;
    int yes_no = 0, amount_update = 0;

    while (current != NULL) {
        if (current -> code == code) {
            if (strcmp(current -> name, name) != 0) {

                printf("\n-> The names are different! Are you sure that you want to overwrite this product (1 - Yes / 2 - No)?: ");
                scanf("%d", &yes_no);

                while(yes_no != 1 && yes_no != 2) {
                    printf("\n-> Invalid option! Choose 1 or 2, please: ");
                    scanf("%d", &yes_no);
                }

                if(yes_no == 1) {

                    strncpy(current -> name, name, sizeof(current -> name) - 1); // Copy name
                    current -> name[sizeof(current -> name) - 1] = '\0'; // Ensure null-termination
                    current -> amount = amount;
                    return 0;

                } else {
                    return 1;
                }

            } else {

                printf("\n-> The names are the same! Do you want to update item information? (1 - Yes / 2 - No)?: ");
                scanf("%d", &yes_no);

                while(yes_no != 1 && yes_no != 2) {
                    printf("\n-> Invalid option! Choose 1 or 2, please: ");
                    scanf("%d", &yes_no);
                }

                if(yes_no == 1) {
                    printf("\n-> Would you like to increase the amount or only update it? Press '1' to increment the amount or '2' to only update it: ");
                    scanf("%d", &amount_update);

                    while(amount_update != 1 && amount_update != 2) {
                        printf("\n-> Invalid option! Choose 1 or 2, please: ");
                        scanf("%d", &amount_update);
                    }

                    if(amount_update == 1) {
                        current -> amount = current -> amount + amount;
                        printf("\n-> Updating item information...\n");
                        return 0;
                    } else {
                        current -> amount = amount;
                        printf("\n-> Updating item information...\n");
                        return 0;
                    }

                } else {
                    return 1;
                }
                
            }
        }

        current = current -> next;

    }

    return 2;

}

void insert_at_the_beginning(Product **product_list, int code, char name[], int amount) {

    int func_return = insertion_validation(product_list, code, name, amount);

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
        new_product -> amount = amount;

        // Set the next pointer of the new node to the current head of the list
        new_product -> next = *product_list;

        // Update the head of the list to point to the new node
        *product_list = new_product;
    }

}

void insert_at_the_end(Product **product_list, int code, char name[], int amount) {

    int func_return = insertion_validation(product_list, code, name, amount);

    if(func_return == 2) {

        Product *aux, *new_product = (Product *)malloc(sizeof(Product));

        if(new_product == NULL) {
            puts("\n-> Memory allocation failed.");
            return;
        }

        new_product -> code = code;
        strncpy(new_product -> name, name, sizeof(new_product -> name) - 1);
        new_product -> name[sizeof(new_product -> name) - 1] = '\0';
        new_product -> amount = amount;

        new_product -> next = NULL;

        // Is this the first node?
        if(*product_list == NULL) {
            *product_list = new_product;
        } else {
            aux = *product_list;
            while(aux -> next) {
                aux = aux -> next;
            }
            aux -> next = new_product;
        }
    }

}

int validate_code_existence(Product **product_list, int prev_code) {

    Product *current = *product_list;
    int found_element = 0;

    while(current != NULL) {
        if (current -> code == prev_code) {
            found_element++;
        }
        current = current -> next;
    }

    if(found_element) {
        printf("\n-> Code found successfully!\n\n");
        return 0;
    } else {
        printf("\n-> The specified code doesn't exist on the list yet. Firstly, insert an element with this code...\n");
        return 1;
    }

}

void insert_at_the_middle(Product **product_list, int code, char name[], int amount, int prev_code) {

    int func_return = insertion_validation(product_list, code, name, amount);

    if(func_return == 2) {

        Product *aux, *new_product = (Product *)malloc(sizeof(Product));

        if(new_product == NULL) {
            puts("\n-> Memory allocation failed.");
            return;
        }

        new_product -> code = code;
        strncpy(new_product -> name, name, sizeof(new_product -> name) - 1);
        new_product -> name[sizeof(new_product -> name) - 1] = '\0';
        new_product -> amount = amount;

        // Is this the first node?
        if(*product_list == NULL) {
            new_product -> next = NULL;
            *product_list = new_product;
        } else {
            aux = *product_list;
            while(aux -> code != prev_code && aux -> next) {
                aux = aux -> next;
            }
            new_product -> next = aux -> next;
            aux -> next = new_product;
        }

    }

}

void insert_sorted(Product **product_list, int code, char name[], int amount) {

    Product *current = *product_list;

    while (current != NULL) {
        if (current -> code == code) {
            current -> amount++;
            return;
        }
        current = current -> next;
    }

    Product *aux, *new_product = (Product *)malloc(sizeof(Product));

    if(new_product == NULL) {
        puts("\n-> Memory allocation failed.");
        return;
    }

    new_product -> code = code;
    strncpy(new_product -> name, name, sizeof(new_product -> name) - 1);
    new_product -> name[sizeof(new_product -> name) - 1] = '\0';
    new_product -> amount = amount;

    // Is the list empty?
    if(*product_list == NULL) {
        new_product -> next = NULL;
        *product_list = new_product;
    } // Is the element the smallest?
    else if(new_product -> code < (*product_list) -> code) {
        new_product -> next = *product_list;
        *product_list = new_product;
    } else {
        aux = *product_list;
        while(aux -> next && new_product -> code > aux -> next -> code){
            aux = aux -> next;
        }
        new_product -> next = aux -> next;
        aux -> next = new_product;
    }

}

void remove_element(Product **product_list, int code) {

    Product *aux, *node_removed = NULL;

    if(*product_list) {
        if((*product_list) -> code == code) {
            if((*product_list) -> amount > 1) {
                (*product_list) -> amount--;
                printf("\n-> Element removed successfully (Code: %d)\n", (*product_list) -> code);
            } else {
                node_removed = *product_list;
                *product_list = node_removed -> next;
                printf("\n-> Element removed successfully (Code: %d)\n", node_removed -> code);
                free(node_removed);
            }
        } else {
            aux = *product_list;

            while(aux -> next && aux -> next -> code != code) {
                aux = aux -> next;
            }

            if(aux -> next) {
                if(aux -> next -> amount > 1) {
                    aux -> next -> amount--;
                    printf("\n-> Element removed successfully (Code: %d)\n", aux -> next -> code);
                } else {
                    node_removed = aux -> next;
                    aux -> next = node_removed -> next;
                    printf("\n-> Element removed successfully (Code: %d)\n", node_removed -> code);
                    free(node_removed);
                }
            }
            else {
                printf("\n-> Element's code not found!\n");
            }
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

    if(product_list == NULL) {
        printf("\n-> The product's list is empty!\n");
    } else {
        printf("\n*** PRODUCTS ***\n\n");
        while(product_list) {

            printf("- Code: %d;\n", product_list -> code);
            printf("- Name: %s;\n", product_list -> name);
            printf("- Total quantity in stock: %d;\n\n", product_list -> amount);

            product_list = product_list -> next;

        }
    }
}

void free_memory(Product *product_list) {
    Product *current = product_list;
    Product *next;

    while (current != NULL) {
        next = current -> next;
        free(current);
        current = next;
    }
}
