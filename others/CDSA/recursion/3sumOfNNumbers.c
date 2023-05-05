// recursive function: the function which calls itself
#include <stdio.h>
int recur(int n)
{
    if (n == -1)
        return 0;
    return n + recur(n - 1);
}
void main()
{
    int n;
    scanf("%d", &n);
    printf("%d", recur(n));
}