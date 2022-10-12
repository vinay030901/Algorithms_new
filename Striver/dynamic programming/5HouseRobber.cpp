/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.



Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.


Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400*/

#include <bits/stdc++.h>
using namespace std;
/*in this question, we need to either pick or not pick, so will either pick the second from index and */
int robRecur(vector<int> &arr, int n, vector<int> &dp)
{
    if (n == 0) // if we reach this position, then we will obviously pick this
        return arr[n];
    if (n < 0) // if value is less than 0, that means we can't take it
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int pick = arr[n] + robRecur(arr, n - 2, dp); // picking the element means we can't take adjacent now
    int notpick = robRecur(arr, n - 1, dp);       // we didn't pick up, so we can take the next adjacent
    return dp[n] = max(pick, notpick);
}
int rob(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n + 1, -1);
    cout << robRecur(arr, n, dp);
}

// BOTTOM UP APPROACH
int rob(vector<int> &arr)
{
    // bottom up approach is only slightly different here
    // we will go from 1 to n but for the case of negative indices, above we returned zero, but one important thing to note is that
    // value of arr was still in it, same is the case here
    // if the indices is less than equal to 1, we will just add the array value to right and not the dp[i-2] because that will
    // point to negative index, so only array will remain added
    int n = arr.size();
    vector<int> dp(n + 1);
    dp[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        int right, left;
        right = arr[i];
        if (i > 1)
            right += dp[i - 2];
        left = dp[i - 1];
        dp[i] = max(left, right);
    }
    return dp[n - 1];
}

// space optimization approach
int rob(vector<int> &arr)
{
    int n = arr.size();
    int prev1 = arr[0], prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int take = arr[i];
        if (i > 1)
            take += prev2;
        int nonTake = prev1;
        int curr = max(take, nonTake);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int main()
{
}
