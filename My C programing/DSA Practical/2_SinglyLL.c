/*Write a C program to design a Singly Linked List and 
perform Insertion at end, Insertion at Beginning, Deletion at 
Begin, Deletion at End, Insertion at Index, Deletion at Index, 
Deletion of entire List and Display Linked List operation on it*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void deleteAtBegin(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* secondLast = *head;
    while (secondLast->next->next != NULL)
        secondLast = secondLast->next;
    free(secondLast->next);
    secondLast->next = NULL;
}

void insertAtIndex(struct Node** head, int data, int index) {
    if (index < 0) {
        printf("Invalid index!\n");
        return;
    }
    if (index == 0) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    int i;
    for (i = 0; temp != NULL && i < index - 1; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid index!\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtIndex(struct Node** head, int index) {
    if (index < 0) {
        printf("Invalid index!\n");
        return;
    }
    if (*head == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return;
    }
    if (index == 0) {
        deleteAtBegin(head);
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    int i;
    for (i = 0; temp != NULL && i < index; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid index!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void deleteList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, index;

    while (1) {
        printf("\nSingly Linked List Operations\n");
        printf("1. Insert at End\n");
        printf("2. Insert at Beginning\n");
        printf("3. Delete at Beginning\n");
        printf("4. Delete at End\n");
        printf("5. Insert at Index\n");
        printf("6. Delete at Index\n");
        printf("7. Delete entire List\n");
        printf("8. Display Linked List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 2:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 3:
                deleteAtBegin(&head);
                break;
            case 4:
                deleteAtEnd(&head);
                break;
            case 5:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter index to insert at: ");
                scanf("%d", &index);
                insertAtIndex(&head, data, index);
                break;
            case 6:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                deleteAtIndex(&head, index);
                break;
            case 7:
                deleteList(&head);
                break;
            case 8:
                displayList(head);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}