/*Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.



Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101


Constraints:

0 <= n <= 105*/

#include <bits/stdc++.h>
using namespace std;
int solve(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;
    if (n & 1)
        return dp[n] = 1 + solve(n / 2, dp);
    else
        return dp[n] = solve(n / 2, dp);
}
vector<int> countBits(int n)
{
    vector<int> ans(n + 1);
    vector<int> dp(n + 1, -1);
    for (int i = 0; i <= n; i++)
    {
        ans[i] = solve(i, dp);
    }
    return ans;
}
int main()
{
}