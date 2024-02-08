#include <stdio.h>
#include <stdlib.h>
 
void main(void)
{
    int m,n,d;
    printf("Enter the size of the first array: ");
    scanf("%d", &m);
    int arr1[m];
    printf("Enter the elements of the first array: \n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr1[i]);
        if(arr1[i]<arr1[i-1])
        {
            d=arr1[i];
            arr1[i]=arr1[i-1];
            arr1[i-1]=d;
        }
    }
    printf("Enter the size of the second array: ");
    scanf("%d", &n);
    int arr2[n];
    printf("Enter the elements of the second array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr2[i]);
        if(arr2[i]<arr2[i-1])
        {
            d=arr2[i];
            arr2[i]=arr2[i-1];
            arr2[i-1]=d;
        }
    }
    int arr3[n + m];
    for (int i=0,j=0,k=0; i <m+n;i++)
    {
        if (arr1[j] < arr2[k])
        {
            arr3[i] = arr1[j];
            j++;
        }
        else
        {
            arr3[i] = arr2[k];
            k++;
        }
    }
    printf("The merged array is: \n");
    for (int i = 0; i < m+n; i++)
    {
        printf("\n%d ", arr3[i]);
    }

}