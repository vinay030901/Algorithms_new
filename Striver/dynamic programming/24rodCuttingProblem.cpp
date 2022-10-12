/*
Given a rod of length ‘N’ units. The rod can be cut into different sizes and each size has a cost associated with it. Determine the maximum cost obtained by cutting the rod and selling its pieces.
Note:
1. The sizes will range from 1 to ‘N’ and will be integers.

2. The sum of the pieces cut should be equal to ‘N’.

3. Consider 1-based indexing.
Input Format:
The first line of input contains an integer ‘T’ denoting the number of test cases.

The next 2 * T lines represent the ‘T’ test cases.

The first line of each test case contains an integer ‘N’ denoting the length of the rod.

The second line of each test case contains a vector ’A’, of size ‘N’ representing the cost of different lengths, where each index of the array is the sub-length and the element at that index is the cost for that sub-length.
Note:
Since 1-based indexing is considered, the 0th index of the vector will represent sub-length 1 of the rod. Hence the (N - 1)th index would represent the cost for the length ‘N’.
Output Format
For each test case, print a single line that contains a single integer which is the maximum cost obtained by selling the pieces.

The output of each test case will be printed in a separate line.
Note:
You do not need to print anything; it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 50
1 <= N <= 100
1 <= A[i] <= 100

Where ‘T’ is the total number of test cases, ‘N’ denotes the length of the rod, and A[i] is the cost of sub-length.

Time limit: 1 sec.

Sample Input 1:
2
5
2 5 7 8 10
8
3 5 8 9 10 17 17 20
Sample Output 1:
12
24
Explanation Of Sample Input 1:
Test case 1:

All possible partitions are:
1,1,1,1,1           max_cost=(2+2+2+2+2)=10
1,1,1,2             max_cost=(2+2+2+5)=11
1,1,3               max_cost=(2+2+7)=11
1,4                 max_cost=(2+8)=10
5                   max_cost=(10)=10
2,3                 max_cost=(5+7)=12
1,2,2               max _cost=(1+5+5)=12

Clearly, if we cut the rod into lengths 1,2,2, or 2,3, we get the maximum cost which is 12.


Test case 2:

Possible partitions are:
1,1,1,1,1,1,1,1         max_cost=(3+3+3+3+3+3+3+3)=24
1,1,1,1,1,1,2           max_cost=(3+3+3+3+3+3+5)=23
1,1,1,1,2,2             max_cost=(3+3+3+3+5+5)=22
and so on….

If we cut the rod into 8 pieces of length 1, for each piece 3 adds up to the cost. Hence for 8 pieces, we get 8*3 = 24.
Sample Input 2:
1
6
3 5 6 7 10 12
Sample Output 2:
18*/

#include <bits/stdc++.h>
using namespace std;

// this problem is simply unbounded knapsack where we have to make the array ourselves
int recur(int n, vector<int> &arr, vector<int> &price, int k, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        return price[n] * (k / arr[n]);
    }
    if (dp[n][k] != -1)
        return dp[n][k];
    int notTake = recur(n - 1, arr, price, k, dp);
    int take = 0;
    if (arr[n] <= k)
        take = price[n] + recur(n, arr, price, k - arr[n], dp);
    dp[n][k] = max(take, notTake);
}
int cutRod(vector<int> &price, int n)
{
    vector<int> arr;
    for (int i = 1; i <= n; i++)
        arr.push_back(i);
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return recur(n - 1, arr, price, n, dp);
}

// more optimized version
int recur(int n, vector<int> &price, int k, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        return price[n] * k;
    }
    if (dp[n][k] != -1)
        return dp[n][k];
    int notTake = recur(n - 1, price, k, dp);
    int take = 0;
    int rodlength = n + 1;
    if (rodlength <= k)
        take = price[n] + recur(n, price, k - rodlength, dp);
    dp[n][k] = max(take, notTake);
}
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return recur(n - 1, price, n, dp);
}

// tabulation
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    int k = n;
    for (int i = 0; i <= k; i++)
        dp[0][i] = i * price[0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            int notTake = dp[i - 1][j];
            int take = 0;
            int rodlength = i + 1;
            if (rodlength <= j)
                take = price[i] + dp[i][j - rodlength];
            dp[i][j] = max(take, notTake);
        }
    }
    return dp[n - 1][k];
}

// space optimized
int cutRod(vector<int> &price, int n)
{
    vector<int> prev(n + 1, 0);
    int k = n;
    for (int i = 0; i <= k; i++)
        prev[i] = i * price[0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            int notTake = prev[j];
            int take = 0;
            int rodlength = i + 1;
            if (rodlength <= j)
                take = price[i] + prev[j - rodlength];
            prev[j] = max(take, notTake);
        }
    }
    return prev[k];
}
int main()
{
}