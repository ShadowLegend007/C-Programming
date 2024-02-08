#include <stdio.h>
void main()
{
    int matrix1[5][5],matrix2[5][5],matrix3[5][5],R,R1,C,C1,Multiply=0;
    printf("Give the highest no. of rows-");
    scanf("%d",&R);
    printf("Give the highest no. of columns-");
    scanf("%d",&C);
    printf("Give the value of the First matrix for the below mentioned positions---\n");
    for(int i=0;i<R;i++)
    {
        for (int j = 0; j < C; j++)
        {
            printf("matrix[%d][%d]=",i,j);
            scanf("%d",&matrix1[i][j]);
        }
    }
    printf("Give the highest no. of rows-");
    scanf("%d",&R1);
    printf("Give the highest no. of columns-");
    scanf("%d",&C1);
    printf("Give the value of the Second matrix for the below mentioned positions---\n");
    for(int i=0;i<R1;i++)
    {
        for (int j = 0; j < C1; j++)
        {
            printf("matrix[%d][%d]=",i,j);
            scanf("%d",&matrix2[i][j]);
        }
    }
    if(C==R1)
    {
        for(int i=0;i<R;i++)
        {
            for (int j = 0; j < C1; j++)
            {
                for(int k=0;k < C;k++)
                {
                    Multiply=(matrix1[i][k]*matrix2[k][j])+Multiply;
                }
                matrix3[i][j]=Multiply;
            }
        }
        printf("After Multiplication the answer is--\n");
        for(int i=0;i<R;i++)
        {
            for (int j = 0; j < C1; j++)
            {
                printf("%d\t",matrix3[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Multiplication can not be done as the no. of columns of First Matrix is not equivalent\n");
        printf("with no. of rows of second Matrix");
    }
}