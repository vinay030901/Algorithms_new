/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.



Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3


Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000*/
#include <bits/stdc++.h>
using namespace std;
int robSpace(vector<int> &arr, int start, int end)
{
    int prev1 = arr[start], prev2 = 0;
    for (int i = start + 1; i < end; i++)
    {
        int pick = arr[i];
        if (i > start + 1)
            pick += prev2;
        int notPick = prev1;
        int curr = max(pick, notPick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int rob(vector<int> &arr)
{
    /*Since House[1] and House[n] are adjacent, they cannot be robbed together. Therefore, the problem becomes to rob either House[1]-House[n-1] or House[2]-House[n], depending on which choice offers more money. Now the problem has degenerated to the House Robber, which is already been solved.*/

    int n = arr.size();
    if (n == 1)
        return arr[0];
    // since first and last can't be together, we will only take either the values from first to second last or second to last
    return max(robSpace(arr, 0, n - 1), robSpace(arr, 1, n));
}
int main()
{
}