#include<stdio.h>
int main()
{
    int num;
    printf("enter a number:");
    scanf("%d", &num);
    if (num>0)
    {
        printf("%d is positive",num);
    }
    else
    {
        printf("%d is negative",num);
    }
}
