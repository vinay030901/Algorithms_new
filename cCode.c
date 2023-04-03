#include <stdio.h>
void fun(int *top)
{
  *top = 20;
}
void fun1(int *b)
{
  *b = 10;
}
int main()
{
  int a = 5;
  fun(&a);
  printf("a = %d\n", a);
}
