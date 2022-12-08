#include <stdio.h>
int main()
{
    int i, m, n, sum = 0;
    printf("enter the number");
    scanf("%d", &n);
    for (i = 1; i <= 10; i++)
    {
        m = n * i;
        printf("%d * %d = %d\n", n, i, m);
    }
    for (i = 1; i <= 10; i++)
    {
        sum = sum + i;
        printf("%d\n", sum);
    }
}