#include<stdio.h>
void main()
{
    int matrix1[5][5],matrixT[5][5],r,c;
     printf("Give the highest no. of rows-");
    scanf("%d",&r);
    printf("Give the highest no. of columns-");
    scanf("%d",&c);
    printf("Give the value of the First matrix for the below mentioned positions---\n");
    for(int i=0;i<r;i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("matrix[%d][%d]=",i,j);
            scanf("%d",&matrix1[i][j]);
        }
    }
    for(int i=0;i<r;i++)
    {
        for (int j = 0; j < c; j++)
        {
            matrixT[j][i]=matrix1[i][j];
        }
    }
    printf("Your Given Mtrix is--");
    for(int i=0;i<c;i++)
    {
        printf("\n");
        for (int j = 0; j < r; j++)
        {
            printf("%d\t",matrixT[i][j]);
        }
    }
}