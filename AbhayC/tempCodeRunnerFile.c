#include <stdio.h>
int main()
{
    int a;
    printf("enter a values of a :");
    scanf("%d", &a);
    if (a== 1)
    {
        printf("weekday is sunday");
    }
    else if (a==2)
    {
        printf("weekday is Monday");
    }
    else if (a==3)
    {
        printf("weekday is tuesday");
    }
    else if (a==4)
    {
        printf("weekday is wednesday");
    }
    else if(a==5)
    {
        printf("weekday is thursday");
    }
    else if (a==6)
    { 
        printf("weekday is  friday"); 
    }
    else if (a==7)
    {
        printf("weekday is saturday");
    }
    else 
    {
        printf("invalid number");
    }     
}

