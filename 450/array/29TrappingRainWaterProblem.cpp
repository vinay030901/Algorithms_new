/*
Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it is able to trap after raining.

Examples:

Input: arr[]   = {2, 0, 2}
Output: 2
We can trap 2 units of water in the middle gap.

Input: arr[]   = {3, 0, 2, 0, 4}
Output: 7

We can trap "3 units" of water between 3 and 2,
"1 unit" on top of bar 2 and "3 units" between 2
and 4.  See below diagram also.

Input: arr[] = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
Output: 6
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // this question looks difficult but it could be solved in O(n) time
    // after analysing the box, we can see that the amount of water filled on a box or space is equal to
    // size of minimum of maximum betweem its right and left-its own size
    // we will add all these space, and find the answer
    // it is evident that no amount of water will get trapped on blocks whose size is local maxima

    // what will we do is to do a prex sum type of exercise and calculate maximum for every element on both sides
    int ml[n], mr[n];
    ml[0] = arr[0];
    for (int i = 1; i < n; i++)
        ml[i] = max(arr[i], ml[i - 1]);
    mr[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        mr[i] = max(arr[i], mr[i + 1]);
    int trapped = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (min(ml[i], mr[i]) > arr[i])
            trapped += (min(ml[i], mr[i]) - arr[i]);
    }
    cout << "trapped rain water: " << trapped;

    // above code take extra space which is not needed.
    // we can understand that we need minimum of max of left and right
    int low = 0, high = n - 1, lmax = 0, rmax = 0, ans = 0;
    ;
    while (low <= high)
    {
        if (arr[low] <= arr[high])
        {
            if (arr[low] > lmax)
                lmax = arr[low];
            else
                ans += (lmax - arr[low]);
            low++;
        }
        else
        {
            if (arr[high] > rmax)
                rmax = arr[high];
            else
                ans += (rmax - arr[high]);
            high--;
        }
    }
    cout << "\nUsing constant space: " << ans;
}