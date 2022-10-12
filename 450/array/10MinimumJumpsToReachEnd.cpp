#include <bits/stdc++.h>
using namespace std;
int MinimumNumberOfJumps(int arr[], int n)
{
    int jumps = 1;         // no of jumps, by default it is 1
    int maxReach = arr[0]; // how much we can reach from a particular position
    int steps = arr[0];    // no of steps we can take from that position, we will use this variable to loop over the other values
    // which we can reach
    for (int i = 1; i < n; i++)
    {
        if (i == n - 1)
            return jumps;
        maxReach = max(maxReach, arr[i] + i);
        steps--;
        if (steps == 0)
        {
            jumps++;
            if (i >= maxReach)
                return -1;
            steps = maxReach - i;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {2, 2, 1, 3, 3, 2, 0, 4, 3, 1, 2, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << MinimumNumberOfJumps(arr, n);
}

/*
int jumps=1;
int maxreach=arr[0];
int steps=arr[0];
for(int i=1; i < n; i++)
{
    maxreach=max(maxreach,arr[i]+i);
    steps--;
    if(i==n-1)
    return jumps;
    if(steps==0)
    {
        jumps++;
        if(i>=maxreach)
        return -1;
        steps=maxreach-i;
    }
    return jumps;
}*/