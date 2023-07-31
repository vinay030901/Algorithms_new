#include <bits/stdc++.h>
using namespace std;
bool canJump(vector<int> &arr)
{
    int maxreach = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (maxreach < i)
            return false;
        maxreach = max(maxreach, i + arr[i]);
    }
    return true;
}
bool canJump(vector<int> &arr)
{
    int n = arr.size(), maxreach = arr[0], steps = arr[0], jumps = 0;
    if (n == 1)
        return true;
    if (arr[0] == 0)
        return false;
    for (int i = 1; i < n; i++)
    {
        maxreach = max(maxreach, arr[i] + i);
        if (i == n - 1)
            return true;
        steps--;
        if (steps == 0)
        {
            if (maxreach <= i)
                return false;
            jumps++;
            steps = maxreach - i;
        }
    }
    return true;
}
int main()
{
}