#include<stdio.h>
int main()
{
    int a,result;
    printf("enter the number :");
    scanf("%d",&a);
result=(a>5);
switch(result)
{
case 0:
    printf("Bye");
    break;
case 1:
    printf("Hello");
        break;
}
}