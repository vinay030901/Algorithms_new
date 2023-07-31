#include <bits/stdc++.h>
using namespaace std;
int jump(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return 0;
    if (arr[0] == 0)
        return -1;
    int jumps = 1, maxreach = arr[0], steps = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (i == n - 1)
            return jumps;
        maxreach = max(maxreach, i + arr[i]);
        steps--;
        if (steps == 0)
        {
            // if(maxreach==i) return -1;
            jumps++;
            steps = maxreach - i;
        }
    }
    return -1;
}