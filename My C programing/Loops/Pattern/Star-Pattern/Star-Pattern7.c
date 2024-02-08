/*
   *
  * *
 * * *
  * *
   *
*/
#include<stdio.h>
void main()
{
    int line;
    printf("Give the highest number of line =");
    scanf("%d",&line);
    for(int i=1;i<=line;i++)
    {
        printf("\n");
        for (int j = 1; j <=(line - i); j++)
        {
            printf(" ");
        }
        for (int k = 1; k <= i; k++)
        {
            printf(" *");
        }
    }
    for(int i=1;i<=line;i++)
    {
        printf("\n");
        for (int j = 1; j <= i; j++)
        {
            printf(" ");
        }
        for (int k = 1; k <= (line-i); k++)
        {
            printf(" *");
        }
    }
}