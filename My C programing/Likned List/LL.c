#include<stdio.h>
#include<stdlib.h>
struct node{
    int val;
    struct node *next;
};
struct node *start = NULL;
int Incert_end(int value)
{
    struct node *tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp -> val = value;
    tmp -> next = NULL;
    if(start == NULL)
    {
        start = tmp;
    }
    else
    {
        struct node *m;
        m = start;
        while( m -> next != NULL)
        {
            m = m -> next;
        }
        m -> next = tmp;
    }
}

void Incert_bgain(int value)
{
    struct node *tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp -> val = value;
    tmp -> next = NULL;
    if(start == NULL)
    {
        start = tmp;
    }
    else
    {
        tmp -> next = start;
        start = tmp;
    }
}

void Incert_any(int value, int index)
{
    if(index == 0)
    {
        Incert_bgain(value);
    }
    else{
        struct node *tmp;
        tmp = (struct node*)malloc(sizeof(struct node));
        tmp -> val = value;
        tmp -> next = NULL;
        if(start == NULL)
        {
            start = tmp;
        }
        else
        {
            struct node *p;
            p = start;
            int count = 0;
            while(count != (index - 1) && p -> next != NULL)
            {
                p = p -> next;
                count++;
            }
            tmp -> next = p -> next;
            p -> next = tmp;
        }
    }
}

void Delete_begin()
{
    struct node *tmp;
    tmp = start;
    start = start -> next;
    free(tmp);
}

void Delete_end()
{
    struct node *tmp;
    struct node *prev;
    tmp = prev = start;
    while( tmp -> next != NULL)
    {
        prev = tmp;
        tmp = tmp -> next;
    }
    free(tmp);
    prev -> next = NULL;
}

void Delete_any( int index )
{
    struct node *tmp;
    struct node *prev;
    tmp = prev = start;
    int count = 0;
    while( count != index && tmp -> next != NULL)
    {
        count ++;
        prev = tmp;
        tmp =  tmp -> next;
    }
    if( count == index)
    {
        prev -> next = tmp -> next;
        free (tmp);
    }
    else if(tmp -> next == NULL)
    {
        printf("This index is not available.\n");
    }
}

void Counter()
{
    struct node *tmp;
    tmp = start;
    int count = 1;
    while( tmp -> next != NULL )
    {
        count++;
        tmp = tmp -> next;
    }
    printf("There have only %d elements.\n",count);
}

void Find(int a)
{
    struct node *tmp;
    tmp = start;
    int count = 0;
    while(tmp -> val != a && tmp -> next != NULL)
    {
        tmp = tmp -> next;
        count ++;
    }
    if(tmp -> val == a)
    {
        printf("This number also present in index no %d .\n",count);
    }
    else if(tmp -> next ==NULL)
    {
        printf("This number is not available.\n");
    }
}

void Delete_num( int num )
{
    struct node *tmp;
    struct node *prev;
    tmp = prev = start;
    while( tmp -> val != num && tmp -> next != NULL)
    {
        prev = tmp;
        tmp =  tmp -> next;
    }
    if( tmp -> val == num)
    {
        prev -> next = tmp -> next;
        free (tmp);
    }
    else if(tmp -> next == NULL)
    {
        printf("This number is not available.\n");
    }
}

void Dispaly()
{
    struct node *m;
    m = start;
    printf("%d\n", m -> val);
    while( m -> next != NULL)
    {
        m = m -> next;
        printf("%d\n", m -> val);
    }
}

char menu()
{
    char key;
    printf("Enter 's' and 'S' for start the program. \nEnter 'a' or 'A' for add any position where you want. \nEnter 'b' or 'B' for add at begain. \nEnter 'c' or 'C' for add at end. \nEnter 'd' or 'D' for display the input. \nEnter 'e' or 'E' for delete an element from begin. \nEnter 'f' or 'F' for delete an element from end. \nEnter 'g' or 'G' for delete an element from any index number. \nEnter 'h' or 'H' for counting. \nEnter 'i' or 'I' for finding any number. \nEnter 'j' or 'J' for delete any number. \nEnter'x' or 'X' for exit from the program. \n");
    scanf("%c",&key);
    return key;
}   
void main()
{
    int a,b,c,index;
    char key;
    while(key != 'x' || key != 'X')
    {   
        key=menu(key);
        switch(key)
        {
            case 's':
            case 'S':
            {
                printf("Enter the box number");
                scanf("%d",&a);
                for(int i = 0; i < a; i++)
                {
                    printf("Enter the %dbox name and value ",i);
                    scanf("%d",&b);
                    Incert_end(b);
                }
                break;
            }
            case 'a':
            case 'A':
            {
                printf("Enter the position number");
                scanf("%d",&index);
                printf("Enter the number which you want to add on %d position",index);
                scanf("%d",&c);
                Incert_any(c,index);
                break;
            }
            case 'b':
            case 'B':
            {
                printf("How many number you want to add at bagin  ");
                scanf("%d",&a);
                for(int i=0; i<a;i++)
                {
                    printf("Enter the number  ");
                    scanf("%d",&c);
                    Incert_bgain(c);
                }
                break;
            }
            case 'c':
            case 'C':
            {
                printf("How many number you want to add at end  ");
                scanf("%d",&a);
                for(int i=0; i<a;i++)
                {
                    printf("Enter the number ");
                    scanf("%d",&c);
                    Incert_end(c);
                }
                break;
            }
            case 'd':
            case 'D':
            {
                Dispaly();
                break;
            }
            case 'e':
            case 'E':
            {
                Delete_begin();
                break;
            }
            case 'f':
            case 'F':
            {
                Delete_end();
                break;
            }
            case 'g':
            case 'G':
            {
                printf("Enter the Index number");
                scanf("%d",&a);
                Delete_any(b);
                break;
            }
            case 'h':
            case 'H':
            {
                Counter();
                break;
            }
            case 'i':
            case 'I':
            {
                printf("Enter the number which you want to find");
                scanf("%d",&a);
                Find(a);
                break;
            }
            case 'j':
            case 'J':
            {
                printf("Enter the number which you want to delete");
                scanf("%d",&a);
                Delete_num(a);
                break;
            }
            case 'x':
            case 'X':
            {
                exit(EXIT_SUCCESS);
                break;
            }
            default :
            {
                printf("Re enter the key\n");
            }
        }
        printf("\n\n");
        scanf("%c",&key);
    }
}