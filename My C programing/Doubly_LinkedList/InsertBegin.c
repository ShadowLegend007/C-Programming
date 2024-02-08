#include<stdio.h>
#include<stdlib.h>
struct list
{
    int num;
    struct list *prev,*next;
};
struct list* start=NULL;
void insert(int num)
{
    struct list* temp=(struct list*)malloc(sizeof(struct list*));
    temp -> num=num;
    temp -> next=temp -> prev=NULL;
    if(start == NULL)
    {
        start=temp;
    }
    else
    {
        temp -> next=start;
        start -> prev=temp;
        start=temp;
    }
}
void display()
{
    struct list* m = start;
    while(m!= NULL)
    {
        printf("%d\n",m -> num);
        m=m -> next;
    }   
}
void main()
{
    int lim,num;
    printf("Write how many numbers you want give:-");
    scanf("%d",&lim);
    printf("Give the numbers ------");
    for(int i=0;i<lim;i++)
    {
        scanf("%d",&num);
        insert(num);
    }
    printf("Your given numbers are-----\n");
    display();
}