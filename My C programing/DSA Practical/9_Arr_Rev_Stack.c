// // Write a C program to reverse an array using stack. You need 
// // to implement the stack first then use that for reversal.

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Stack {
	int top;
	unsigned capacity;
	char* array;
};


struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack
		= (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array
		= (char*)malloc(stack->capacity * sizeof(char));
	return stack;
}


int isFull(struct Stack* stack)
{
	return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}

void push(struct Stack* stack, char item)
{
	if (isFull(stack))
		return;
	stack->array[++stack->top] = item;
}


char pop(struct Stack* stack)
{
	if (isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top--];
}

void reverse(char str[])
{
	
	int n = strlen(str);
	struct Stack* stack = createStack(n);

	int i;
	for (i = 0; i < n; i++)
		push(stack, str[i]);

	
	for (i = 0; i < n; i++)
		str[i] = pop(stack);
}


int main()
{
	char str[100];
    printf("Enter the string:\n");
    scanf("%[^\n]s", &str);

	reverse(str);
	printf("Reversed string is %s", str);

	return 0;
}
