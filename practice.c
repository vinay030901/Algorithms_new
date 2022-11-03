#include <stdio.h>
int main()
{
  int c;
  printf("enter the number: ");
  scanf("%d", &c);
  printf("sizeof operator: %d\n", sizeof(c));  // sizeof operator
  printf("address of operator: %d\n", &c);     // address of operator
  printf("pre increment operator: %d\n", ++c); // pre increment operator
  c++;
  printf("post increment operator: %d\n", c); // post increment operator

  printf("pre decrement operator: %d\n", --c); // pre decrement operator
  c--;                                         // post decrement operator
  printf("post decrement operator: %d\n", c);
}
