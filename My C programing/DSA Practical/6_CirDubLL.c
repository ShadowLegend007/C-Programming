/* Write a C program to design a Circular Doubly Linked List 
and perform Insertion at end, Insertion at Beginning, Deletion at 
Begin, Deletion at End, Insertion at Index, Deletion at Index, 
Deletion of entire List, and Display Circular Doubly Linked List 
operation*/
#include <stdio.h>
#include <stdlib.h>

// Structure for a circular doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the circular doubly linked list
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        newNode->next = newNode->prev = newNode; // Point to itself
        *head = newNode;
    } else {
        newNode->next = (*head)->next;
        newNode->prev = *head;
        (*head)->next->prev = newNode;
        (*head)->next = newNode;
    }
}

// Function to insert a node at the end of the circular doubly linked list
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        newNode->next = newNode->prev = newNode; // Point to itself
        *head = newNode;
    } else {
        newNode->next = (*head)->next;
        newNode->prev = *head;
        (*head)->next->prev = newNode;
        (*head)->next = newNode;
        *head = newNode;
    }
}

// Function to delete a node from the circular doubly linked list
void deleteNode(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node* curr = (*head)->next;
    while (curr != *head) {
        if (curr->data == value) {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            free(curr);
            printf("Node with value %d deleted.\n", value);
            return;
        }
        curr = curr->next;
    }
    printf("Node with value %d not found.\n", value);
}

// Function to display the circular doubly linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Circular Doubly Linked List is empty.\n");
        return;
    }
    struct Node* temp = head->next;
    printf("Circular Doubly Linked List: ");
    while (temp != head) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d -> ... (loop)\n", head->data);
}

int main() {
    struct Node* head = NULL;
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Delete a node\n");
        printf("4. Display the circular doubly linked list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to insert at the beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2:
                printf("Enter a value to insert at the end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                printf("Enter a value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 4:
                displayList(head);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    // Clean up memory (optional)
    while (head != NULL) {
        struct Node* temp = head->next;
        free(head);
        head = temp;
    }

    return 0;
}
