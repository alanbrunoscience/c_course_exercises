#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a node in the linked list
typedef struct Node {
    char name[50];
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node into the linked list
void insert(Node** head, char* name) {
    Node* newNode = createNode(name);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to print the contacts in the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%s -> ", current->name);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to initialize the array of linked lists
void initializeList(Node* list[]) {
    for (int i = 0; i < 26; i++) {
        list[i] = NULL;
    }
}

int main() {
    // Array of 26 linked lists, one for each letter of the alphabet
    Node* contacts[26];

    // Initialize the list
    initializeList(contacts);

    // Insert some contacts
    insert(&contacts[0], "Alan"); // A
    insert(&contacts[0], "Aline"); // A
    insert(&contacts[1], "Bianca"); // B
    insert(&contacts[2], "Carlos"); // C
    insert(&contacts[2], "Cintia"); // C

    // Print the contacts per letter
    for (int i = 0; i < 26; i++) {
        if (contacts[i] != NULL) {
            printf("%c: ", 'A' + i);
            printList(contacts[i]);
        }
    }

    return 0;
}
