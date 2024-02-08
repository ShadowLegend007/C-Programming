#include<stdio.h>
#include<stdlib.h>
struct list
{
    int num;
    struct list* add;
};
struct list* start = NULL;
void insert(int num)
{
    struct list* temp = (struct list*)malloc(sizeof(struct list*));
    temp -> num=num;
    temp -> add=NULL;
    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        struct list* m=start;
        while(m -> add != NULL)
        {
            m=m -> add;
        }
        m -> add=temp;
    }
}
void display()
{
    struct list* m=start;
    printf("%d\n",m -> num);
    while(m -> add != NULL)
    {
        m=m -> add;
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