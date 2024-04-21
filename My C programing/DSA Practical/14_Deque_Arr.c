/*Write a C program to implement Deque using array. Perform 
the operations add to front, add to rear, delete from front, delete 
from rear, and display.*/
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Structure for the deque
struct Deque {
    int arr[MAX_SIZE];
    int front;
    int rear;
};

// Initialize an empty deque
void initializeDeque(struct Deque* dq) {
    dq->front = -1;
    dq->rear = -1;
}

// Check if the deque is empty
bool isEmpty(struct Deque* dq) {
    return dq->front == -1;
}

// Check if the deque is full
bool isFull(struct Deque* dq) {
    return (dq->front == 0 && dq->rear == MAX_SIZE - 1) || (dq->front == dq->rear + 1);
}

// Add an element to the front of the deque
void addToFront(struct Deque* dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full. Cannot add.\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX_SIZE - 1;
    } else {
        dq->front--;
    }
    dq->arr[dq->front] = value;
}

// Add an element to the rear of the deque
void addToRear(struct Deque* dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full. Cannot add.\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else if (dq->rear == MAX_SIZE - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }
    dq->arr[dq->rear] = value;
}

// Delete an element from the front of the deque
void deleteFromFront(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty. Cannot delete.\n");
        return;
    }
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->front == MAX_SIZE - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
}

// Delete an element from the rear of the deque
void deleteFromRear(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty. Cannot delete.\n");
        return;
    }
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = MAX_SIZE - 1;
    } else {
        dq->rear--;
    }
}

// Display the deque
void displayDeque(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque: ");
    int i = dq->front;
    while (i != dq->rear) {
        printf("%d -> ", dq->arr[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", dq->arr[i]);
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
