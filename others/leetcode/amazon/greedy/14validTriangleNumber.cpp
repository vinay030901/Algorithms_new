/*
Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we
take them as side lengths of a triangle.

Example 1:

Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are:
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Example 2:

Input: nums = [4,2,3,4]
Output: 4
*/
#include <bits/stdc++.h>
using namespace std;
int triangleNumber(vector<int> &arr)
{
    // this question is like 3-sum, where we are fixing the last element because we will compare the previous values
    // one thing we know about property of triangle is sum of two sides is greater than one side
    // so when we sort this, we compare the lower side to be higher than larger side, and therefore we are fixing i from the end

    sort(arr.begin(), arr.end());
    int ans = 0;
    int n = arr.size();
    for (int i = n - 1; i > 1; i--)
    {
        for (int low = 0, high = i - 1; low < high;)
        {
            if ((arr[low] + arr[high]) > arr[i])
            {
                // we are adding value of high-low to answer because sum of if low being added to high is greater than ith value
                // that means every value after low being added to high will be greater than ith value, since the array is sorted
                ans += (high - low);
                high--;
            }
            else
                low++;
        }
    }
    return ans;
}
int main()
{
}