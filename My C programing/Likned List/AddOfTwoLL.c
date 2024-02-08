#include<stdio.h>
#include<stdlib.h>
struct list
{
    int num;
    struct list * add;
};
struct list * insert(int num,struct list * start)
{
    struct list * temp = (struct list *)malloc(sizeof(struct list *));
    temp -> num=num;
    temp -> add=NULL;
    if(start == NULL)
    {
        start = temp;
    }
    else
    {
        struct list * m=start;
        while(m -> add != NULL)
        {
            m=m -> add;
        }
        m -> add=temp;
    }
    return start;
}
void display(struct list* start)
{
    struct list * m=start;
    while(m != NULL)
    {
        printf("%d\n",m -> num);
        m=m -> add;
    }
}
struct list * add_of_list(struct list *list1,struct list *list2,struct list *list3)
{
    struct list * m=list1;
    struct list * n=list2;
    while(m != NULL)
    {
        int sum=m -> num + n -> num;
        list3=insert(sum,list3);
        m=m -> add;
        n=n -> add;
    }
    return list3;
}
void main()
{
    int size,data;
    struct list* list1=NULL;
    struct list* list2=NULL;
    struct list* list3=NULL;
    printf("Give How many numbers you wnt to give:- ");
    scanf("%d",&size);
    printf("Give the numbers of two lists-----\n");
    for(int i=0;i<size;i++)
    {
        printf("Give the number of position %d of first list:- ",i+1);
        scanf("%d",&data);
        list1=insert(data,list1);
        printf("Give the number of position %d of second list:- ",i+1);
        scanf("%d",&data);
        list2=insert(data,list2);
    }
    list3=add_of_list(list1,list2,list3);
    printf("The addition of each elements are-----\n");
    display(list3);
}