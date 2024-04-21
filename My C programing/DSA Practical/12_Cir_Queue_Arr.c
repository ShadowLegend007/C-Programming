// Write a C program to implement circular queue using array. 
// You need to perform Enqueue and Dequeue operation on this 
// data structure. 


#include<stdio.h>
#include<stdlib.h>

int front=-1,rear=-1,*queue;

void enqueue(int x,int size){
    if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
    }else if(((rear+1)%size)==front){
        printf("Queue is full\n");
    }else{
        rear=(rear+1)%size;
        queue[rear]=x;
    }
}

void dequeue(int size){
    if(front ==-1 && rear==-1){
        printf("Empty Queue\n");
    }else if(front == rear){
        front=rear=-1;
    }else{
        printf("%d",queue[front]);
        front=(front+1)%size;
    }
}

void display(int size){
    int i=front;
    if(front==-1 && rear==-1){
        printf("Queue is empty\n");
    }else{
        printf("The queue is:\n");
        while(i!=rear){
            printf("%d ",queue[i]);
            i=(i+1)%size;
        }
        printf("%d\t",queue[rear]);
    }
}

void peek(){
    if(front==-1 && rear==-1){
        printf("Queue is empty\n");
        }
    else{
        printf("%d",queue[front]);
        }
}

int main(){
    int choice, value;
    int size;
    printf("Enter the size of the queue:\n");
    scanf("%d",&size);
    queue=(int *)malloc(size* sizeof(int));

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                enqueue(value,size);
                break;

            case 2:
                dequeue(size);
                break;

            case 3:
                peek();
                break;
            case 4:
                display(size);
                break;
            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
 
    return 0;
}