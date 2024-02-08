#include<stdio.h>
#include<stdlib.h>
struct list
{
    int value;
    struct list* add;
};
struct list* start=NULL;
void insert(int num)
{
    struct list* temp=(struct list*)malloc(sizeof(struct list*));
    temp -> value=num;
    temp -> add=NULL;
    if(start == NULL)
    {
        start=temp;
    }
    else
    {
        temp -> add=start;
        start=temp;
    }
}
void display()
{
    struct list* m = start;
    while(m!= NULL)
    {
        printf("%d\n",m -> value);
        m=m -> add;
    }   
}
void main()
{
    int lim,num;
    printf("Write how many numbers you want give:-");
    scanf("%d",&lim);
    for(int i=0;i<lim;i++)
    {
        scanf("%d",&num);
        insert(num);
    }
    printf("Your diven numbers are-----\n");
    display();
}