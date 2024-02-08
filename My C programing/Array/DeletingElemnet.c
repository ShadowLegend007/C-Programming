#include<stdio.h>
#include<stdlib.h>
void main()
{
    int* arr;
    int n,num;
    printf("Enter the numbers of elements:");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("Enter the elements:");
    for (int i=0;i<n;i++)
    {
        printf("Array[%d]=",i);
        scanf("%d",&arr[i]);
    }
    printf("Write which element you want to delete:-");
    scanf("%d",&num);
    for (int i=0;i<n;i++)
    {
       if(arr[i]==num)
       {
        for(;i<n;i++)
        {
            if(i+1<n)
            arr[i]=arr[i+1];
            else
            arr[i]=0;
        }
        break;
       }
    }
    printf("The new arr elements are");
    for (int i=0;i<n;i++)
    {
        printf("\t%d",arr[i]);
    }
}