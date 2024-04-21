/* Write a C program to convert an equation to Postfix and 
Prefix with the help of a Stack. Implement the Stack using 
Linked List. */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define the structure for the stack node
typedef struct StackNode {
    char data;
    struct StackNode* next;
} StackNode;

// Function to create a new stack node
StackNode* newNode(char data) {
    StackNode* stackNode = (StackNode*)malloc(sizeof(StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

// Function to check if the stack is empty
int isEmpty(StackNode* root) {
    return !root;
}

// Function to push an element to the stack
void push(StackNode** root, char data) {
    StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
}

// Function to pop an element from the stack
char pop(StackNode** root) {
    if (isEmpty(*root))
        return '\0';
    StackNode* temp = *root;
    *root = (*root)->next;
    char popped = temp->data;
    free(temp);
    return popped;
}

// Function to peek the top element of the stack
char peek(StackNode* root) {
    if (isEmpty(root))
        return '\0';
    return root->data;
}

// Function to check the precedence of operators
int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Function to convert infix expression to postfix
void infixToPostfix(char* exp, char* result) {
    int i, k;
    StackNode* stack = NULL;
    for (i = 0, k = -1; exp[i]; ++i) {
        // If the scanned character is an operand, add it to the output
        if (isalnum(exp[i])) {
            result[++k] = exp[i];
        }
        // If the scanned character is '(', push it to the stack
        else if (exp[i] == '(') {
            push(&stack, exp[i]);
        }
        // If the scanned character is ')', pop and output from the stack until '(' is encountered
        else if (exp[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                result[++k] = pop(&stack);
            }
            if (!isEmpty(stack) && peek(stack) != '(')
                return; // Invalid expression
            else
                pop(&stack);
        }
        // If an operator is scanned
        else if (isOperator(exp[i])) {
            while (!isEmpty(stack) && precedence(exp[i]) <= precedence(peek(stack))) {
                result[++k] = pop(&stack);
            }
            push(&stack, exp[i]);
        }
    }
    // Pop all the remaining elements from the stack
    while (!isEmpty(stack)) {
        result[++k] = pop(&stack);
    }
    result[++k] = '\0';
}

// Function to reverse a string
void reverse(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Function to convert infix expression to prefix
void infixToPrefix(char* exp, char* result) {
    // Reverse the infix expression
    reverse(exp);
    // Replace '(' with ')' and vice versa
    for (int i = 0; exp[i]; i++) {
        if (exp[i] == '(') {
            exp[i] = ')';
            i++;
        } else if (exp[i] == ')') {
            exp[i] = '(';
            i++;
        }
    }
    // Get the postfix expression of the reversed infix expression
    infixToPostfix(exp, result);
    // Reverse the postfix expression to get the prefix expression
    reverse(result);
}

// Main function
int main() {
    char exp[] = "A+B*(C^D-E)"; // Example infix expression
    char postfix[100];
    char prefix[100];

    infixToPostfix(exp, postfix);
    printf("Postfix: %s\n", postfix);

    infixToPrefix(exp, prefix);
    printf("Prefix: %s\n", prefix);

    return 0;
}