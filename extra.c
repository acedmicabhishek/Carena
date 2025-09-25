#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Node {
    int data;
    struct Node *next;
} Node;


Node* createNode(int data);
Node* insertAtBeginning(Node *head, int data);
void printList(Node *head);
void freeList(Node *head);



Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Failed to allocate memory for new node");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtBeginning(Node *head, int data) {
    Node *newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

void printList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeList(Node *head) {
    Node *current = head;
    Node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}


int main (){
    Node *head = NULL; 

    printf("Creating a linked list:\n");
    head = insertAtBeginning(head, 30);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 10);

    printf("Printing the linked list: ");
    printList(head); 

    printf("Freeing the linked list.\n");
    freeList(head); 
    head = NULL; 

    printf("Linked list operations complete.\n");

    return 0;
}