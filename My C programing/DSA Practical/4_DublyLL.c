/*Write a C program to design a Doubly Linked List and 
perform Insertion at end, Insertion at Beginning, Deletion at 
Begin, Deletion at End, Insertion at Index, Deletion at Index, 
Deletion of entire List, Reverse operation, and Display Linked 
List operation on it.*/
#include <stdio.h>
#include <stdlib.h>

// Structure for a circular linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the circular linked list
void insertAtBeginning(struct Node** head, int value) 
{
    struct Node* newNode = createNode(value);
    if (*head == NULL) 
    {
        newNode->next = newNode; 
        *head = newNode;
    } 
    else 
    {
        newNode->next = (*head)->next;
        (*head)->next = newNode;
    }
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node** head, int value) 
{
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        newNode->next = newNode; // Point to itself
        *head = newNode;
    } else {
        newNode->next = (*head)->next;
        (*head)->next = newNode;
        *head = newNode;
    }
}

// Function to display the circular linked list
void displayList(struct Node* head) 
{
    if (head == NULL) 
    {
        printf("Circular Linked List is empty.\n");
        return;
    }
    struct Node* temp = head->next;
    printf("Circular Linked List: ");
    while (temp != head) 
    {
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
        printf("3. Display the circular linked list\n");
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
