#include <stdio.h>
void main()
{
    int matrix[5][5],limR,limC,count=0;
    printf("Give the highest no. of rows-");
    scanf("%d",&limR);
    printf("Give the highest no. of columns-");
    scanf("%d",&limC);
    printf("Give the value of the matrix for the below mentioned positions---\n");
    for(int i=0;i<limR;i++)
    {
        for (int j = 0; j < limC; j++)
        {
            printf("matrix[%d][%d]=",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
    for(int i=0;i<limR;i++)
    {
        for(int j=0;j<limC;j++)
        {
            for(int k=0;k<limR;k++)
            {
                for (int l = 0; l < limC; l++)
                {
                    if(matrix[i][j]==matrix[k][l])
                    {
                        count++;
                    }
                } 
            }
            printf("\nIn this matrix the element %d contains %d times",matrix[i][j],count);
            count=0;
        }
    }
}