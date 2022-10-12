/*
You are given an array of ‘N’ distinct integers and an integer ‘X’ representing the target sum. You have to tell the minimum number of elements you have to take to reach the target sum ‘X’.
Note:
You have an infinite number of elements of each type.
For Example
If N=3 and X=7 and array elements are [1,2,3]. 
Way 1 - You can take 4 elements  [2, 2, 2, 1] as 2 + 2 + 2 + 1 = 7.
Way 2 - You can take 3 elements  [3, 3, 1] as 3 + 3 + 1 = 7.
Here, you can see in Way 2 we have used 3 coins to reach the target sum of 7.
Hence the output is 3.
Input Format :
The first line of the input contains an integer, 'T’, denoting the number of test cases.

The first line of each test case will contain two space-separated integers ‘N’ and ‘X’, denoting the size of the array and the target sum.

The second line of each test case contains ‘N’ space-separated integers denoting elements of the array.
Output Format :
For each test case, print the minimum number of coins needed to reach the target sum ‘X’, if it's not possible to reach to target then print "-1".

Print a separate line for each test case.
Note :
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
1 <= N <= 15
1 <= nums[i] <= (2^31) - 1
1 <= X <= 10000

All the elements of the “nums” array will be unique.
Time limit: 1 sec*/

#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int recur(vector<int> &arr, int n, int p, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        if (p % arr[0] == 0)
            return p / arr[0];
        return 1e9;
    }
    if (dp[n][p] != -1)
        return dp[n][p];
    int notTake = recur(arr, n - 1, p, dp);
    int take = INT_MAX;
    if (arr[n] <= p)
        take = 1 + recur(arr, n, p - arr[n], dp);
    return dp[n][p] = min(take, notTake);
}
int minimumElements(vector<int> &arr, int p)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(p + 1, -1));
    int ans = recur(arr, n - 1, p, dp);
    if (ans >= 1e9)
        return -1;
    return ans;
}
int minimumElements(vector<int> &arr, int p)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(p + 1, 0));
    for (int i = 0; i <= p; i++)
        if (i % arr[0] == 0)
            dp[0][i] = (i / arr[0]);
        else
            dp[0][i] = 1e9;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= p; j++)
        {
            int notTake = dp[i - 1][j];
            int take = INT_MAX;
            if (arr[i] <= j)
                take = dp[i][j - arr[i]] + 1;
            dp[i][j] = min(take, notTake);
        }
    }
    return dp[n - 1][p] >= 1e9 ? -1 : dp[n - 1][p];
}
int minimumElements(vector<int> &arr, int p)
{
    int n = arr.size();
    vector<int> prev(p + 1, 0), cur(p + 1, 0);
    for (int i = 0; i <= p; i++)
        if (i % arr[0] == 0)
            prev[i] = (i / arr[0]);
        else
            prev[i] = 1e9;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= p; j++)
        {
            int notTake = prev[j];
            int take = INT_MAX;
            if (arr[i] <= j)
                take = 1 + cur[j - arr[i]];
            cur[j] = min(take, notTake);
        }

        prev = cur;
    }
    int ans = prev[p];
    if (ans >= 1e9)
        return -1;
    return ans;
}
int main()
{
}