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
void print_list(Node *node);

int main() {

    int option, num, previous_element;
    Node *list = NULL;
    
    do {

        printf("\n\t0 - Exit;\n\t1 - Insert at the beginning;\n\t2 - Insert at the end;\n\t3 - Insert at the middle;\n\t4 - Print list.\n");
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
                
                print_list(list);

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

    Node *new = malloc(sizeof(Node));

    if(new == NULL) {
        puts("\n-> Memory allocation failed.");
        exit(1);
    }

    new -> value = num;
    new -> next = *list; // The content of the list once the list is an array, its content points to the first position of the memory of this array.
    *list = new;

}

void insert_at_the_end(Node **list, int num) {

    Node *aux, *new = malloc(sizeof(Node));

    if(new == NULL) {
        puts("\n-> Memory allocation failed.");
        exit(1);
    }

    new -> value = num;
    new -> next = NULL;

    // Is this the first node?
    if(*list == NULL) {
        *list = new;
    } else {
        aux = *list;
        while(aux -> next) {
            aux = aux -> next;
        }
        aux -> next = new;
    }

}

void insert_at_the_middle(Node **list, int num, int previous_element) {

    Node *aux, *new = malloc(sizeof(Node));

    if(new == NULL) {
        puts("\n-> Memory allocation failed.");
        exit(1);
    }

    new -> value = num;

    // Is this the first node?
    if(*list == NULL) {
        new -> next = NULL;
        *list = new;
    } else {
        aux = *list;
        while(aux -> value != previous_element && aux -> next) {
            aux = aux -> next;
        }
        new -> next = aux -> next;
        aux -> next = new;
    }

}

void print_list(Node *list) {

    printf("\n\tList: ");
    while(list) {
        printf("%d ", list -> value);
        list = list -> next;
    }
    printf("\n\n");

}