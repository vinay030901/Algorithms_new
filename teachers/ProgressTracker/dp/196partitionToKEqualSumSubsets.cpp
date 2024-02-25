/*Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.



Example 1:

Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
Example 2:

Input: nums = [1,2,3,4], k = 3
Output: false


Constraints:

1 <= k <= nums.length <= 16
1 <= nums[i] <= 104
The frequency of each element is in the range [1, 4].*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool recur(int &persum, int i, int curr, int k, vector<int> &arr, vector<bool> &vis)
    {
        if (k == 1)
            return true;
        if (i >= arr.size())
            return false;
        if (curr == persum)
            return recur(persum, 0, 0, k - 1, arr, vis);
        for (int ind = i; ind < arr.size(); ind++)
        {
            if (vis[ind] || arr[ind] + curr > persum)
                continue;
            vis[ind] = true;
            if (recur(persum, ind + 1, curr + arr[ind], k, arr, vis))
                return true;
            vis[ind] = false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int> &arr, int k)
    {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum % k != 0)
            return false;
        int persum = sum / k;
        vector<bool> vis(arr.size(), false);
        sort(arr.begin(), arr.end(), greater<int>());
        return recur(persum, 0, 0, k, arr, vis);
    }
};
int main()
{
    // Your code here
    return 0;
}