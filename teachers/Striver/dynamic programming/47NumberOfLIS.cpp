/*
Given an integer array nums, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.



Example 1:

Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:

Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.


Constraints:

1 <= nums.length <= 2000
-106 <= nums[i] <= 106*/

#include <bits/stdc++.h>
using namespace std;
int findNumberOfLIS(vector<int> &arr)
{
    int n = arr.size();
    int mx = 1;
    vector<int> lis(n, 1), cnt(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                if (lis[i] < lis[j] + 1)
                {
                    lis[i] = lis[j] + 1;
                    // inherit
                    cnt[i] = cnt[j];
                }
                else if (lis[i] == lis[j] + 1)
                {
                    // increase the count
                    cnt[i] += cnt[j];
                }
            }
        }
        mx = max(mx, lis[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (lis[i] == mx)
            ans += cnt[i];
    return ans;
}
int main()
{
}