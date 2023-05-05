// recursive function: the function which calls itself
#include <stdio.h>
void recur(int n)
{
    if (n == -1)
        return;
    printf("%d ", n);
    recur(n - 1);
    return;
}
void main()
{
    int n;
    scanf("%d", &n);
    recur(n);
}