// Write a C program to implement Last in First out (LIFO) data 
// structure and perform Push, Pop, Peek operations on it. Use 
// array to implement the same. 

#include <stdio.h>
#include <stdlib.h>

int *stack;
int top = -1;

void push(int value, int size) {
    if (top == size - 1) {
        printf("Error: Stack overflow!\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("Error: Stack underflow!\n");
        return -1;
    }
    return stack[top--];
}

void peek(){
    printf("%d\n", stack[top]);
}

int main() {
    int choice, value,size;
    printf("Enter the size of the stack:\n");
    scanf("%d", &size);
    stack=(int*)malloc(size* sizeof(int));


    while (1) {
        printf("1. Push\n2. Pop\n3. Peek\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value,size);
                break;

            case 2:
                value = pop();
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;

            case 3:
                peek();
                break;
            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}