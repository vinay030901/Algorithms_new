/*Given an integer array nums, you need to find one continuous subarray such that if you only sort this subarray in non-decreasing order, then the whole array will be sorted in non-decreasing order.

Return the shortest such subarray and output its length.



Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Example 2:

Input: nums = [1,2,3,4]
Output: 0
Example 3:

Input: nums = [1]
Output: 0


Constraints:

1 <= nums.length <= 104
-105 <= nums[i] <= 105


Follow up: Can you solve it in O(n) time complexity?*/
#include <bits/stdc++.h>
using namespace std;
/*
max on left, min on right - O(N)
The idea is that:

From the left, for a number to stay untouched, there need to be no number less than it on the right hand side;
From the right, for a number to stay untouched, there need to be no number greater than it on the left hand side;
Those 2 can be easily checked if we build 2 vectors:

max so far from the left,
and min so far from the right;
/**
 *            /------------\
 * nums:  [2, 6, 4, 8, 10, 9, 15]
 * minr:   2  4  4  8   9  9  15
 *         <--------------------
 * maxl:   2  6  6  8  10 10  15
 *         -------------------->
 */
class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int Min = INT_MAX;
        int Max = INT_MIN;

        if (n == 1)
            return 0;

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                if (nums[i] > nums[i + 1])
                {
                    Min = min(Min, nums[i]);
                    Max = max(Max, nums[i]);
                }
            }
            else if (i == n - 1)
            {
                if (nums[i] < nums[i - 1])
                {
                    Min = min(Min, nums[i]);
                    Max = max(Max, nums[i]);
                }
            }
            else
            {
                if (nums[i] > nums[i + 1] || nums[i] < nums[i - 1])
                {
                    Min = min(Min, nums[i]);
                    Max = max(Max, nums[i]);
                }
            }
        }

        if (Min == INT_MAX || Max == INT_MIN)
            return 0;
        int i = 0, j = n - 1;
        while (i < n && nums[i] <= Min)
            i++;
        while (j >= 0 && nums[j] >= Max)
            j--;
        return j - i + 1;
    }
};
int main()
{
    // Your code here
    return 0;
}