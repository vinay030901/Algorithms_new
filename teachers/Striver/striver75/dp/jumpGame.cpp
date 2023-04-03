#include <bits/stdc++.h>
using namespace std;
bool canJump(vector<int> &arr)
{
    int reach = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (reach < i)
            return false;
        reach = max(reach, i + arr[i]);
    }
    return true;
}

bool canJump(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return true;
    if (arr[0] == 0)
        return false;
    int maxreach = arr[0], steps = arr[0], jumps = 0;
    for (int i = 1; i < n; i++)
    {
        if (i == n - 1)
            return true;
        steps--;
        maxreach = max(maxreach, i + arr[i]);
        if (steps == 0)
        {
            if (i >= maxreach)
                return false;
            jumps++;
            steps = maxreach - i;
        }
    }
    return false;
}
int main(int argc, const char **argv)
{
    return 0;
}