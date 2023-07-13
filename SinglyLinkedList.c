#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}


void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* currNode = *head;
    while (currNode->next != NULL) {
        currNode = currNode->next;
    }
    currNode->next = newNode;
}


void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* currNode = head;
    while (currNode != NULL) {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }
    printf("\n");
}


void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* currNode = *head;
    struct Node* prevNode = NULL;
    if (currNode->data == data) {
        *head = currNode->next;
        free(currNode);
        return;
    }
    while (currNode != NULL && currNode->data != data) {
        prevNode = currNode;
        currNode = currNode->next;
    }
    if (currNode == NULL) {
        printf("Node not found in the list!\n");
        return;
    }
    prevNode->next = currNode->next;
    free(currNode);
}


void deleteList(struct Node** head) {
    struct Node* currNode = *head;
    struct Node* nextNode;
    while (currNode != NULL) {
        nextNode = currNode->next;
        free(currNode);
        currNode = nextNode;
    }
    *head = NULL;
}

int main() {
    struct Node* head = NULL;
    

    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);
    
    printf("Linked list: ");
    displayList(head);
    
 
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    
   
    printf("Linked list: ");
    displayList(head);
    
   
    deleteNode(&head, 3);
    
   
    printf("Linked list after deletion: ");
    displayList(head);
    
    deleteList(&head);
    
    return 0;
}
