/*Write a C program to implement Deque using linked list. 
Perform the operations add to front, add to rear, delete from 
front, delete from rear, and display.*/
#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Structure for the deque
struct Deque {
    struct Node* front;
    struct Node* rear;
};

// Initialize an empty deque
void initializeDeque(struct Deque* dq) {
    dq->front = NULL;
    dq->rear = NULL;
}

// Check if the deque is empty
int isEmpty(struct Deque* dq) {
    return dq->front == NULL;
}

// Add an element to the front of the deque
void addToFront(struct Deque* dq, int value) {
    struct Node* newNode = createNode(value);
    if (dq->front == NULL) {
        dq->front = newNode;
        dq->rear = newNode;
    } else {
        newNode->next = dq->front;
        dq->front->prev = newNode;
        dq->front = newNode;
    }
}

// Add an element to the rear of the deque
void addToRear(struct Deque* dq, int value) {
    struct Node* newNode = createNode(value);
    if (dq->rear == NULL) {
        dq->front = newNode;
        dq->rear = newNode;
    } else {
        newNode->prev = dq->rear;
        dq->rear->next = newNode;
        dq->rear = newNode;
    }
}

// Delete an element from the front of the deque
void deleteFromFront(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty. Cannot delete.\n");
        return;
    }
    struct Node* temp = dq->front;
    if (dq->front == dq->rear) {
        dq->front = NULL;
        dq->rear = NULL;
    } else {
        dq->front = dq->front->next;
        dq->front->prev = NULL;
    }
    free(temp);
}

// Delete an element from the rear of the deque
void deleteFromRear(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty. Cannot delete.\n");
        return;
    }
    struct Node* temp = dq->rear;
    if (dq->front == dq->rear) {
        dq->front = NULL;
        dq->rear = NULL;
    } else {
        dq->rear = dq->rear->prev;
        dq->rear->next = NULL;
    }
    free(temp);
}

// Display the deque
void displayDeque(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }
    struct Node* temp = dq->front;
    printf("Deque: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Deque dq;
    initializeDeque(&dq);

    int choice, value;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add to front\n");
        printf("2. Add to rear\n");
        printf("3. Delete from front\n");
        printf("4. Delete from rear\n");
        printf("5. Display deque\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to add to front: ");
                scanf("%d", &value);
                addToFront(&dq, value);
                break;
            case 2:
                printf("Enter a value to add to rear: ");
                scanf("%d", &value);
                addToRear(&dq, value);
                break;
            case 3:
                deleteFromFront(&dq);
                break;
            case 4:
                deleteFromRear(&dq);
                break;
            case 5:
                displayDeque(&dq);
                break;
            case 0:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
