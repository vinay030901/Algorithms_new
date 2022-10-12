/*
Given an array ‘ARR’, partition it into two subsets (possibly empty) such that their union is the original array. Let the sum of the elements of these two subsets be ‘S1’ and ‘S2’.
Given a difference ‘D’, count the number of partitions in which ‘S1’ is greater than or equal to ‘S2’ and the difference between ‘S1’ and ‘S2’ is equal to ‘D’. Since the answer may be too large, return it modulo ‘10^9 + 7’.


If ‘Pi_Sj’ denotes the Subset ‘j’ for Partition ‘i’. Then, two partitions P1 and P2 are considered different if:
1) P1_S1 != P2_S1 i.e, at least one of the elements of P1_S1 is different from P2_S2.
2) P1_S1 == P2_S2, but the indices set represented by P1_S1 is not equal to the indices set of P2_S2. Here, the indices set of P1_S1 is formed by taking the indices of the elements from which the subset is formed.
Refer to the example below for clarification.


Note that the sum of the elements of an empty subset is 0.
For Example :
If N = 4, D = 3, ARR = {5, 2, 5, 1}
There are only two possible partitions of this array.
Partition 1: {5, 2, 1}, {5}. The subset difference between subset sum is: (5 + 2 + 1) - (5) = 3
Partition 2: {5, 2, 1}, {5}. The subset difference between subset sum is: (5 + 2 + 1) - (5) = 3
These two partitions are different because, in the 1st partition, S1 contains 5 from index 0, and in the 2nd partition, S1 contains 5 from index 2.*/
#include <bits/stdc++.h>
using namespace std;
// the solution of this question is similar to the above questions
// here we need to find the two subsets with the given difference
// so we need s1 and s2
// we know that s1 + s2 =sum(s)
// and          s1 - s2 =d
// adding both equations, we get
// 2*s1=(sum+d)
// s1 = (sum+d)/2
// we can do this using both memoization and bottom up
int mod = 1e9 + 7;
int recur(vector<int> &arr, int n, int k, vector<vector<int>> &dp)
{
    // extra to handle values with zero
    // extra to handle values with zero
    // if (n == 0)
    // {
    //     if (k == 0 and arr[0] == 0)
    //         return 2; // we have reached zero and we have take present into consideration too
    //     if (k == 0 || k == arr[0])
    //         return 1; // we can take one of then into consideration, since arr[0] is not zero
    //     return 0;
    // }
    if (n == 0)
    {
        if (k == 0 and arr[0] == 0)
            return 2;
        else if (k == 0 or arr[0] == k)
            return 1;
        else
            return 0;
    }
    if (dp[n][k] != -1)
        return dp[n][k];
    int notTake = recur(arr, n - 1, k, dp) % mod;
    int take = 0;
    if (arr[n] <= k)
        take = recur(arr, n - 1, k - arr[n], dp) % mod;
    return dp[n][k] = (take + notTake) % mod;
}
int countPartitions(int n, int d, vector<int> &arr)
{
    // Write your code here.
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if ((sum + d) % 2 != 0)
        return 0;
    int k = (sum + d) / 2;
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    int ans = recur(arr, n - 1, k, dp);
    return ans;
}

int countPartitions(int n, int d, vector<int> &arr)
{
    int mod = 1e9 + 7;
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if ((sum + d) % 2 != 0)
        return 0;
    int target = (sum + d) / 2;
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    if (arr[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;
    if (arr[0] != 0 && arr[0] <= target)
        dp[0][arr[0]] = 1;

    for (int i = 1; i < n; i++)
        for (int j = 0; j <= target; j++)
        {
            int notTake = dp[i - 1][j];
            int take = 0;
            if (arr[i] <= j)
                take = dp[i - 1][j - arr[i]];
            dp[i][j] = (take + notTake) % mod;
        }
    return dp[n - 1][target];
}
int main()
{
}