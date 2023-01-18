/*Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.



Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]


Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.*/

#include <bits/stdc++.h>
using namespace std;
vector<int> productExceptSelf(vector<int> &arr)
{
    int left = 1, right = 1, n = arr.size();
    vector<int> ans(n, 1);
    for (int i = 0; i < n; i++)
    {
        ans[i] *= left;
        ans[n - i - 1] *= right;
        left *= arr[i];
        right *= arr[n - i - 1];
    }
    return ans;
}
int main()
{
}