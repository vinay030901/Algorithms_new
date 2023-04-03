/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water
it can trap after raining.

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9*/
#include <bits/stdc++.h>
using namespace std;
int trap(vector<int> &arr)
{
    // the intution is simple here, we need to find the max till now from both right and left side
    // then we will take the min of them and minus the element value
    // since the element will carry the water which is to the level of min of left and right biggest building
    int n = arr.size();
    vector<int> left(n, 0), right(n, 0);
    int mxl = 0, mxr = 0;
    for (int i = 0, j = n - 1; i < n; i++, j--)
    {
        mxl = max(mxl, arr[i]);
        mxr = max(mxr, arr[j]);
        left[i] = mxl;
        right[j] = mxr;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (min(left[i], right[i]) - arr[i]);
    }
    return ans;
}
int main()
{
}