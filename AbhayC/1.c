#include<stdio.h>
int main()
{ int c=5
printf("sizeof operator:%d",sizeof(c));
printf("address of operator:%d,&c);
printf("pre increment operator:%d",++c);
printf("post increment operator:%d",c++);
printf("pre decrement operator:%d",--c);
printf("post decrement operator:%d",c--);
}