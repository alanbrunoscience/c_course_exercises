#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "products_list.h"

int check_item_existence_av_prod_list(Available_prod **av_prod_list, int code, char name[], int quantity) {

    Available_prod *aux_av = *av_prod_list;

    while(aux_av != NULL) {
        if(aux_av -> code == code) {
            if(strcmp(aux_av -> name, name) != 0) {
                int function_return = update_available_item_diff_name(aux_av, name, quantity);
                return function_return;
            } else {
                int function_return = update_available_item_same_name(aux_av, quantity);
                return function_return;
            }
        }
        aux_av = aux_av -> next;
    }

    return 2;

}

int update_available_item_diff_name(Available_prod *aux_av, char name[], int quantity) {

    int yes_no;

    printf("\n-> The names are different! Do you want to overwrite this product? (1 - Yes / 2 - No): ");
    scanf("%d", &yes_no);

    while(yes_no != 1 && yes_no != 2) {
        printf("\n-> Invalid option! Choose 1 or 2, please: ");
        scanf("%d", &yes_no);
    }

    if(yes_no == 1) {

        strncpy(aux_av -> name, name, sizeof(aux_av -> name) - 1);
        aux_av -> name[sizeof(aux_av -> name) - 1] = '\0';
        aux_av -> quantity = quantity;

        printf("\n-> Updating item information...\n");

        return 0;

    } else {

        printf("\n-> Discarding changes...\n");

        return 1;

    }

}

int update_available_item_same_name(Available_prod *aux_av, int quantity) {

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
            aux_av -> quantity = aux_av -> quantity + quantity;
            printf("\n-> Incrementing the quantity...\n");
            return 0;
        } else {
            printf("\n-> Overwriting the quantity to the new value inserted...\n");
            aux_av -> quantity = quantity;
            return 0;
        }

    } else {

        printf("\n-> Discarding changes...\n");

        return 1;
    }

}

int check_item_existence_unav_prod_list(Available_prod **av_prod_list, Unavailable_prod **unav_prod_list, int code, char name[], int quantity) {

    Unavailable_prod *aux_unav = *unav_prod_list;

    while(aux_unav != NULL) {
        if(aux_unav -> code == code) {
            if(strcmp(aux_unav -> name, name) != 0) {
                int function_return = update_unavailable_item_diff_name(av_prod_list, unav_prod_list, aux_unav, name, quantity);
                return function_return;

            } else {
                int function_return = update_unavailable_item_same_name(av_prod_list, unav_prod_list, aux_unav, name, quantity);
                return function_return;
            }
        }
        aux_unav = aux_unav -> next;
    }

    return 2;

}

int update_unavailable_item_diff_name(Available_prod **av_prod_list, Unavailable_prod **unav_prod_list, Unavailable_prod *aux_unav, char name[], int quantity) {

    int yes_no;

    printf("\n-> The element has already been inserted and deleted previously, but the data is different::\n");

    printf("\n*** ELEMENT PREVIOUS INFO ***\n\n");
    printf("-> Code: %d\n", aux_unav -> code);
    printf("-> Name: %s\n", aux_unav -> name);

    printf("\n-> Would you like to restore it, overwriting the data? (1 - Yes / 2 - No): ");
    scanf("%d", &yes_no);

    while(yes_no != 1 && yes_no != 2) {
        printf("\n-> Invalid option! Choose 1 or 2, please: ");
        scanf("%d", &yes_no);
    }

    if(yes_no == 1) {

        insert_in_available_prod_list(av_prod_list, (aux_unav -> code), name, quantity);
        remove_from_unavailable_list(unav_prod_list, (aux_unav -> code));
        return 0;

    } else {

        printf("\n-> Discarding changes...\n");

        return 1;

    }

}

int update_unavailable_item_same_name(Available_prod **av_prod_list, Unavailable_prod **unav_prod_list, Unavailable_prod *aux_unav, char name[], int quantity) {

    int yes_no;

    printf("\n-> The element has already been inserted and deleted previously:\n");

    printf("\n*** ELEMENT PREVIOUS INFO ***\n\n");
    printf("-> Code: %d\n", aux_unav -> code);
    printf("-> Name: %s\n", aux_unav -> name);

    printf("\n-> Would you like to restore it? (1 - Yes / 2 - No): ");
    scanf("%d", &yes_no);

    while(yes_no != 1 && yes_no != 2) {
        printf("\n-> Invalid option! Choose 1 or 2, please: ");
        scanf("%d", &yes_no);
    }

    if(yes_no == 1) {

        insert_in_available_prod_list(av_prod_list, (aux_unav -> code), name, quantity);
        remove_from_unavailable_list(unav_prod_list, (aux_unav -> code));
        return 0;
        
    } else {

        printf("\n-> Discarding changes...\n");

        return 1;

    }
    
}

void insert_in_available_prod_list(Available_prod **av_prod_list, int code, char name[], int quantity) {
   
    Available_prod *aux, *new_product = (Available_prod *)malloc(sizeof(Available_prod));

    if(new_product == NULL) {
        puts("\n-> Memory allocation failed.");
        return;
    }

    new_product -> code = code;
    strncpy(new_product -> name, name, sizeof(new_product -> name) - 1);
    new_product -> name[sizeof(new_product -> name) - 1] = '\0';
    new_product -> quantity = quantity;

    if(*av_prod_list == NULL) {

        new_product -> next = NULL;
        *av_prod_list = new_product;

    } else if(new_product -> code < (*av_prod_list) -> code) {

        new_product -> next = *av_prod_list;
        *av_prod_list = new_product;

    } else {

        aux = *av_prod_list;

        while(aux -> next && new_product -> code > aux -> next -> code) {
            aux = aux -> next;
        }

        new_product -> next = aux -> next;
        aux -> next = new_product;

    }

}

void remove_from_unavailable_list(Unavailable_prod **unav_prod_list, int code) {

    Unavailable_prod *aux, *node_removed;

    if((*unav_prod_list) -> code == code) {
        
        node_removed = *unav_prod_list;
        *unav_prod_list = node_removed -> next;
        free(node_removed);

    } else {

        aux = *unav_prod_list;

        while(aux -> next -> code != code) {
            aux = aux -> next;
        }

        node_removed = aux -> next;
        aux -> next = node_removed -> next;
        free(node_removed);

    }

}

void remove_from_available_listI(Available_prod **av_prod_list, Unavailable_prod **unav_prod_list, int code, int quantity) {

    Available_prod *aux, *node_removed;

    if((*av_prod_list) -> code == code) {
        
        node_removed = *av_prod_list;

        if(node_removed -> quantity == quantity) {
            *av_prod_list = node_removed -> next;
            node_removed -> quantity = node_removed -> quantity - quantity;
            insert_in_unavailable_prod_list(unav_prod_list, code, (node_removed -> name), (node_removed -> quantity));
            printf("\n-> Element completely removed - Code %d.\n", node_removed -> code);
            free(node_removed);
        } else {
            node_removed -> quantity = node_removed -> quantity - quantity;
            printf("\n-> Element's quantity updated to %d.\n", node_removed -> quantity);
        }

    } else {

        aux = *av_prod_list;

        while(aux -> next -> code != code) {
            aux = aux -> next;
        }

        node_removed = aux -> next;

        if(node_removed -> quantity == quantity) {
            aux -> next = node_removed -> next;
            node_removed -> quantity = node_removed -> quantity - quantity;
            insert_in_unavailable_prod_list(unav_prod_list, code, (node_removed -> name), (node_removed -> quantity));
            printf("\n-> Element completely removed - Code %d.\n", node_removed -> code);
            free(node_removed);
        } else {
            node_removed -> quantity = node_removed -> quantity - quantity;
            printf("\n-> Element's quantity updated to %d.\n", node_removed -> quantity);
        }

    }

}

void remove_from_available_listII(Available_prod **av_prod_list, int code) {

    Available_prod *aux, *node_removed;

    if((*av_prod_list) -> code == code) {
        
        node_removed = *av_prod_list;
        *av_prod_list = node_removed -> next;
        free(node_removed);

    } else {

        aux = *av_prod_list;

        while(aux -> next -> code != code) {
            aux = aux -> next;
        }

        node_removed = aux -> next;
        aux -> next = node_removed -> next;
        free(node_removed);

    }

}

void remove_av_prod_permanently(Available_prod **av_prod_list, int code) {

    int yes_no;

    printf("\n-> This option cannot be reversed. Are you sure you want to remove this product permanently? (1 - Yes / 2 - No): ");
    scanf("%d", &yes_no);

    while(yes_no != 1 && yes_no != 2) {
        printf("\n-> Invalid option! Choose 1 or 2, please: ");
        scanf("%d", &yes_no);
    }

    if(yes_no == 1) {

        remove_from_available_listII(av_prod_list, code);
        printf("\n-> Code removed permanently!\n");
        
    } else {

        printf("\n-> Discarding changes...\n");

    }

}

void remove_unav_prod_permanently(Unavailable_prod **unav_prod_list, int code) {

    int yes_no;

    printf("\n-> This option cannot be reversed. Are you sure you want to remove this product permanently? (1 - Yes / 2 - No): ");
    scanf("%d", &yes_no);

    while(yes_no != 1 && yes_no != 2) {
        printf("\n-> Invalid option! Choose 1 or 2, please: ");
        scanf("%d", &yes_no);
    }

    if(yes_no == 1) {

        remove_from_unavailable_list(unav_prod_list, code);
        printf("\n-> Code removed permanently!\n");
        
    } else {

        printf("\n-> Discarding changes...\n");

    }

}

void insert_in_unavailable_prod_list(Unavailable_prod **unav_prod_list, int code, char name[], int quantity) {
   
    Unavailable_prod *aux, *new_product = (Unavailable_prod *)malloc(sizeof(Unavailable_prod));

    if(new_product == NULL) {
        puts("\n-> Memory allocation failed.");
        return;
    }

    new_product -> code = code;
    strncpy(new_product -> name, name, sizeof(new_product -> name) - 1);
    new_product -> name[sizeof(new_product -> name) - 1] = '\0';
    new_product -> quantity = quantity;

    if(*unav_prod_list == NULL) {

        new_product -> next = NULL;
        *unav_prod_list = new_product;

    } else if(new_product -> code < (*unav_prod_list) -> code) {

        new_product -> next = *unav_prod_list;
        *unav_prod_list = new_product;

    } else {

        aux = *unav_prod_list;

        while(aux -> next && new_product -> code > aux -> next -> code) {
            aux = aux -> next;
        }

        new_product -> next = aux -> next;
        aux -> next = new_product;

    }

}

Available_prod* search_available_product(Available_prod **av_prod_list, int code) {

    Available_prod *aux, *node_found = NULL;

    aux = *av_prod_list;

    while(aux && aux -> code != code) {
        aux = aux -> next;
    }

    if(aux) {
        node_found = aux;
    }

    return node_found;

}

Unavailable_prod* search_unavailable_product(Unavailable_prod **unav_prod_list, int code) {

    Unavailable_prod *aux, *node_found = NULL;

    aux = *unav_prod_list;

    while(aux && aux -> code != code) {
        aux = aux -> next;
    }

    if(aux) {
        node_found = aux;
    }

    return node_found;

}

int validate_code_existence_av_list(Available_prod **av_prod_list, int code) {

    Available_prod *current_elem = *av_prod_list;
    int found_element = 0;

    while(current_elem != NULL) {
        if (current_elem -> code == code) {
            found_element++;
        }
        current_elem = current_elem -> next;
    }

    if(found_element) {

        return 0;

    } else {
        
        return 1;

    }

}

int validate_code_existence_unav_list(Unavailable_prod **unav_prod_list, int code) {

    Unavailable_prod *current_elem = *unav_prod_list;
    int found_element = 0;

    while(current_elem != NULL) {
        if (current_elem -> code == code) {
            found_element++;
        }
        current_elem = current_elem -> next;
    }

    if(found_element) {
        
        return 0;

    } else {
        
        return 1;
        
    }

}

void generate_available_prod_report(Available_prod *av_prod_list, Unavailable_prod *unav_prod_list, char filename_av_prod[]) {

    FILE *fptr;

    if((fptr = fopen(filename_av_prod, "wb")) == NULL) {
        puts("\n-> Unable to create the file. Finishing the program...");
        free_memory(av_prod_list, unav_prod_list);
        exit(1);
    }

    fputs("*** AVAILABLE PRODUCTS ***\n", fptr);
    while(av_prod_list) {
        fprintf(fptr, "\n- Code: %d\n", av_prod_list -> code);
        fprintf(fptr, "- Name: %s\n", av_prod_list -> name);
        fprintf(fptr, "- Total quantity in stock: %d\n", av_prod_list -> quantity);

        av_prod_list = av_prod_list -> next;

    }

    fclose(fptr);

}

void generate_unavailable_prod_report(Available_prod *av_prod_list, Unavailable_prod *unav_prod_list, char filename_unav_prod[]) {

    FILE *fptr;

    if((fptr = fopen(filename_unav_prod, "wb")) == NULL) {
        puts("\n-> Unable to create the file. Finishing the program...");
        free_memory(av_prod_list, unav_prod_list);
        exit(1);
    }

    fputs("*** UNAVAILABLE PRODUCTS ***\n", fptr);
    while(unav_prod_list) {
        fprintf(fptr, "\n- Code: %d\n", unav_prod_list -> code);
        fprintf(fptr, "- Name: %s\n", unav_prod_list -> name);
        fprintf(fptr, "- Total quantity in stock: %d\n", unav_prod_list -> quantity);

        unav_prod_list = unav_prod_list -> next;

    }

    fclose(fptr);

}

void print_av_prod_list(Available_prod *av_prod_list, Unavailable_prod *unav_prod_list, char filename_av_prod[]) {

    FILE *fptr;
    char *str = NULL;
    size_t len = 0;

    if ((fptr = fopen(filename_av_prod, "r")) == NULL) {
        puts("\n-> Unable to open the file for reading.");
        free_memory(av_prod_list, unav_prod_list);
        exit(1);
    }

    while (getline(&str, &len, fptr) != -1) {
        printf("%s", str);
    }

    free(str);

    fclose(fptr);
    
}

void print_unav_prod_list(Available_prod *av_prod_list, Unavailable_prod *unav_prod_list, char filename_unav_prod[]) {

    FILE *fptr;
    char *str = NULL;
    size_t len = 0;

    if ((fptr = fopen(filename_unav_prod, "r")) == NULL) {
        puts("\n-> Unable to open the file for reading.");
        free_memory(av_prod_list, unav_prod_list);
        exit(1);
    }

    while (getline(&str, &len, fptr) != -1) {
        printf("%s", str);
    }

    free(str);

    fclose(fptr);
    
}

void free_memory(Available_prod *av_prod_list, Unavailable_prod *unav_prod_list) {

    Available_prod *current_av_prod = av_prod_list, *nextI;
    Unavailable_prod *current_unav_prod = unav_prod_list, *nextII;

    while (current_av_prod != NULL) {
        nextI = current_av_prod -> next;
        free(current_av_prod);
        current_av_prod = nextI;
    }

    while (current_unav_prod != NULL) {
        nextII = current_unav_prod -> next;
        free(current_unav_prod);
        current_unav_prod = nextII;
    }

}