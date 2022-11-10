#include<stdio.h>
int main()
{
int a,b,result;
  printf("enter the value of a : ");
 scanf("%d",&a);
 printf("enter the value of b : ");
 scanf("%d",&b);
result=(a>b)&&(a+b>0);
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