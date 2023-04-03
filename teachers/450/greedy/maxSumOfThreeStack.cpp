#include <bits/stdc++.h>
using namespace std;
int main()
{
    int st1[] = {3, 2, 1, 1, 1}, st2[] = {4, 3, 2}, st3[] = {1, 1, 4, 1};
    int n1 = sizeof(st1) / sizeof(st1[0]), n2 = sizeof(st2) / sizeof(st2[0]), n3 = sizeof(st3) / sizeof(st3[0]);
    int sum1 = accumulate(st1, st1 + n1, 0);
    int sum2 = accumulate(st2, st2 + n2, 0);
    int sum3 = accumulate(st3, st3 + n3, 0);
    int top1 = 0, top2 = 0, top3 = 0;
    while (1)
    {
        if (top1 == n1 || top2 == n2 || top3 == n3)
        {
            cout << 0;
            break;
        }
        if (sum1 == sum2 && sum2 == sum3)
        {
            cout << sum1;
            break;
        }
        else if (sum1 >= sum2 && sum1 >= sum3)
            sum1 -= st1[top1++];
        else if (sum2 >= sum1 && sum2 >= sum3)
            sum2 -= st2[top2++];
        else
            sum3 -= st3[top3++];
    }
}