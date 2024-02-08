#include<stdio.h>
#include<math.h>
void main()
{
    int i=1900,year,diff,leap=0,days=0,totaldays;
    printf("Give the year = ");
    scanf("%d",&year);
    diff=year-i;
    if (diff<0)
    {
        diff=abs(diff);
    }
    
    for ( ; i < year; i++)
    {
        if ((i%400==0)||(i%4==0 && i%100!=0))
        {
            leap++;
        }
    }
    days=(365*(diff-leap)+366*leap);
    days=days%7;
    printf("The day 1st January of the year %d is-",year);
    switch (days)
    {
        case 0:
            printf("Monday");
            break;
        case 1:
            printf("Tuesday");
            break;
        case 2:
            printf("Wednesday");
            break;
        case 3:
            printf("Thursday");
            break;
        case 4:
            printf("Friday");
            break;
        case 5:
            printf("Saturday");
            break;
        case 6:
            printf("Sunday");
            break;
        
        default:
            break;
    }
}