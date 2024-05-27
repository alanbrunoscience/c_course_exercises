#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct ListNode {
    int data;
    struct ListNode* next;
} ListNode;

// Functions prototype
ListNode* merge(ListNode* list1, ListNode* list2);
void splitList(ListNode* source, ListNode** frontRef, ListNode** backRef);
void mergeSort(ListNode** headRef);
void push(ListNode** headRef, int newData);
void printList(ListNode* node);

// Function to merge two sorted linked lists
ListNode* merge(ListNode* list1, ListNode* list2) {

    printf("list1: ");
    printList(list1);
    printf("list2: ");
    printList(list2);

    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    ListNode* mergedList = NULL;

    if (list1->data <= list2->data) {
        mergedList = list1;
        mergedList->next = merge(list1->next, list2);
    } else {
        mergedList = list2;
        mergedList->next = merge(list1, list2->next);
    }

    return mergedList;
}

// Function to split the linked list into two halves
void splitList(ListNode* source, ListNode** frontRef, ListNode** backRef) {
    
    if (source == NULL || source->next == NULL) {
        *frontRef = source;
        *backRef = NULL;
        return;
    }

    ListNode* slow = source;
    ListNode* fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

// Function to perform merge sort on linked list
void mergeSort(ListNode** headRef) {

    ListNode* head = *headRef;
    ListNode* a;
    ListNode* b;

    // Base case: If list is empty or has only one node, return
    if (head == NULL || head->next == NULL) {
        return;
    }

    // Split the list into two halves
    splitList(head, &a, &b);    

    // Recursively sort the sublists
    mergeSort(&a);
    mergeSort(&b);

    printf("a: %d\n", a->data);
    printf("b: %d\n", b->data);
    printf("\n");

    // Merge the sorted sublists
    *headRef = merge(a, b);

}

// Function to insert a node at the beginning of the linked list
void push(ListNode** headRef, int newData) {
    
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
    
}

// Function to print the linked list
void printList(ListNode* node) {
    
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");

}

// Main function for testing
int main() {
    
    ListNode* head = NULL;

    // Insert elements into the linked list
    push(&head, 4);
    push(&head, 2);
    push(&head, 1);
    push(&head, 3);

    printf("Original list: ");
    printList(head);

    // Sort the linked list using merge sort
    mergeSort(&head);

    printf("Sorted list: ");
    printList(head);

    return 0;

}