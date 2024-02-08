#include<stdio.h>
#include<stdlib.h>
struct list
{
    int num;
    struct list* prev,*next;
};
struct list* start = NULL;
void insert(int num)
{
    struct list* temp = (struct list*)malloc(sizeof(struct list*));
    temp -> num=num;
    temp -> next=temp -> prev=NULL;
    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        struct list* m=start;
        while(m != NULL)
        {
            m=m -> next;
        }
        m -> next=temp;
        temp -> prev=m;
    }
}
void display()
{
    struct list* m=start;
    printf("%d\n",m -> num);
    while(m != NULL)
    {
        m=m -> next;
        printf("%d\n",m -> num);
    }
}
void main()
{
    int size,data;
    printf("Give How many numbers you wnt to give:- ");
    scanf("%d",&size);
    printf("Give the numbers--\n");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&data);
        insert(data);
    }
    printf("Your diven numbers are-----\n");
    display();
}