// Write a C program to implement Push, Pop, Peek operations 
// of Stack using Linked List.

#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * link;
}*top;

    void push(int data){
        struct node * temp=(struct node *)malloc(sizeof(struct node));

        while(!temp){
            printf("\n Stack is over flowed.\n");
        }

        temp->data=data;
        temp->link=top;
        top=temp;

    }

  
    int peek(){
        if(top==NULL){
            printf("The stack is empty..\n");
        }else{
            printf("%d\n",top->data);
        }
    }

    void pop(){
        struct node * temp=(struct node *)malloc(sizeof(struct node));

        if(top == NULL){
            printf("Under flow condition..\n");
        }else{
            temp=top;
            printf("The poped element: %d",temp->data);
            top=top->link;
            free(temp);
        }


    }
int main(){
    int choice,value;
     while (1) {
        printf("1. Push\n2. Pop\n3. Peek\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
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