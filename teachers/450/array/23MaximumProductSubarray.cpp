#include <bits/stdc++.h>
using namespace std;
int main()
{

    //int arr[] = {2, 3, -7, 0, 3, -4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // so, our claim here is that the answer is lying in subarray from starting or from ending
    // that is we will start from start and multiply till end, until we have 0, and we will find mx while doing that
    // same we will be doing from ending too
    int curr = 1, mx = INT_MIN;
    for (int i = 0; i < n; i++) // traversing from start to end
    {
        curr *= arr[i];
        mx = max(mx, curr); // finding the max value
        if (arr[i] == 0)
            curr = 1;
    }
    curr = 1;
    for (int i = n - 1; i >= 0; i--) // now traversing from end to start
    {
        curr *= arr[i];
        mx = max(mx, curr);
        if (arr[i] == 0)
            curr = 1;
    }
    cout << mx;
}