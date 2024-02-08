#include <stdio.h>
void main()
{
    int matrix1[5][5],matrix2[5][5],limR,limC;
    printf("Give the highest no. of rows-");
    scanf("%d",&limR);
    printf("Give the highest no. of columns-");
    scanf("%d",&limC);
    printf("Give the value of the First matrix for the below mentioned positions---\n");
    for(int i=0;i<limR;i++)
    {
        for (int j = 0; j < limC; j++)
        {
            printf("matrix[%d][%d]=",i,j);
            scanf("%d",&matrix1[i][j]);
        }
    }
    printf("Give the value of the Second matrix for the below mentioned positions---\n");
    for(int i=0;i<limR;i++)
    {
        for (int j = 0; j < limC; j++)
        {
            printf("matrix[%d][%d]=",i,j);
            scanf("%d",&matrix2[i][j]);
        }
    }
    printf("Your Given Mtrix is--");
    for(int i=0;i<limR;i++)
    {
        printf("\n");
        for (int j = 0; j < limC; j++)
        {
            printf("%d\t",matrix1[i][j]+matrix2[i][j]);
        }
    }
}