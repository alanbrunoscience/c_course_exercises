#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

    int value;
    struct Node *next;

} Node;

// Functions prototype
void insert_at_the_beginning(Node **list, int num);
void insert_at_the_end(Node **list, int num);
void insert_at_the_middle(Node **list, int num, int previous_element);
void insert_sorted(Node **list, int num);
Node* remove_element(Node **list, int num);
Node* search_element(Node **list, int num);
void print_list(Node *node);

int main() {

    int option, num, previous_element;
    Node *search_node, *node_removed, *list = NULL;
    
    do {

        printf("\n\t0 - Exit;\n\t1 - Insert at the beginning;\n\t2 - Insert at the end;\n\t3 - Insert at the middle;\n\t4 - Insert sorted;\n\t5 - Remove element;\n\t6 - Print list;\n\t7 - Search element.\n");
        scanf("%d", &option);

        switch (option) {
            case 1:

                printf("Enter an integer value: ");
                scanf("%d", &num);

                insert_at_the_beginning(&list, num);

                break;

            case 2:

                printf("Enter an integer value: ");
                scanf("%d", &num);

                insert_at_the_end(&list, num);

                break;

            case 3:

                printf("Enter an integer value and a value of reference: ");
                scanf("%d %d", &num, &previous_element);

                insert_at_the_middle(&list, num, previous_element);

                break;

            case 4:

                printf("Enter an integer value: ");
                scanf("%d", &num);
                
                insert_sorted(&list, num);

                break;

            case 5:

                printf("Enter the integer value to be removed: ");
                scanf("%d", &num);
                
                node_removed = remove_element(&list, num);

                if(node_removed) {
                    printf("\n-> Element to be removed: %d\n", node_removed -> value);
                    free(node_removed);
                } else {
                    printf("\n-> Element not found!\n");
                }

                break;
                
            case 6:

                print_list(list);

                break;

            case 7:

                printf("Enter an integer value to be searched: ");
                scanf("%d", &num);
                
                search_node = search_element(&list, num);

                if(search_node) {
                    printf("\n-> Element found: %d\n", search_node -> value);
                } else {
                    printf("\n-> Element not found!\n");
                }

                break;

            default:
                if(option != 0) {
                    printf("\n-> Invalid option!\n");
                }
        }

    } while(option != 0);

    return 0;

}

void insert_at_the_beginning(Node **list, int num) {

    Node *new_node = malloc(sizeof(Node));

    if(new_node == NULL) {
        puts("\n-> Memory allocation failed.");
        exit(1);
    }

    new_node -> value = num;
    new_node -> next = *list; // The content of the list once the list is an array, its content points to the first position of the memory of this array.
    *list = new_node;

}

void insert_at_the_end(Node **list, int num) {

    Node *aux, *new_node = malloc(sizeof(Node));

    if(new_node == NULL) {
        puts("\n-> Memory allocation failed.");
        exit(1);
    }

    new_node -> value = num;
    new_node -> next = NULL;

    // Is this the first node?
    if(*list == NULL) {
        *list = new_node;
    } else {
        aux = *list;
        while(aux -> next) {
            aux = aux -> next;
        }
        aux -> next = new_node;
    }

}

void insert_at_the_middle(Node **list, int num, int previous_element) {

    Node *aux, *new_node = malloc(sizeof(Node));

    if(new_node == NULL) {
        puts("\n-> Memory allocation failed.");
        exit(1);
    }

    new_node -> value = num;

    // Is this the first node?
    if(*list == NULL) {
        new_node -> next = NULL;
        *list = new_node;
    } else {
        aux = *list;
        while(aux -> value != previous_element && aux -> next) {
            aux = aux -> next;
        }
        new_node -> next = aux -> next;
        aux -> next = new_node;
    }

}

void insert_sorted(Node **list, int num) {

    Node *aux, *new_node = malloc(sizeof(Node));

    if(new_node == NULL) {
        puts("\n-> Memory allocation failed.");
        exit(1);
    }

    new_node -> value = num;
    
    // Is the list empty?
    if(*list == NULL) {
        new_node -> next = NULL;
        *list = new_node;
    } // Is the element the smallest?
    else if(new_node -> value < (*list) -> value) {
        new_node -> next = *list;
        *list = new_node;
    } else {
        aux = *list;
        while(aux -> next && new_node -> value > aux -> next -> value){
            aux = aux -> next;
        }
        new_node -> next = aux -> next;
        aux -> next = new_node;
    }

}

Node* remove_element(Node **list, int num) {

    Node *aux, *node_removed = NULL;

    if(*list) {
        if((*list) -> value == num) {
            node_removed = *list;
            *list = node_removed -> next;
        } else {
            aux = *list;
            while(aux -> next && aux -> next -> value != num) {
                aux = aux -> next;
            }
            if(aux -> next) {
                node_removed = aux -> next;
                aux -> next = node_removed -> next;
            }
        }
    }

    return node_removed;

}

Node* search_element(Node **list, int num) {

    Node *aux, *node_found = NULL;

    aux = *list;

    while(aux && aux -> value != num) {
        aux = aux -> next;
    }

    if(aux) {
        node_found = aux;
    }

    return node_found;

}

void print_list(Node *node) {

    printf("\n\tList: ");
    while(node) {
        printf("%d ", node -> value);
        node = node -> next;
    }
    printf("\n\n");

}