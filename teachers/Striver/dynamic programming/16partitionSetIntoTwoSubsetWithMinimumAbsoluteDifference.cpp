#include <bits/stdc++.h>
using namespace std;
int partitonSet(vector<int> &arr)
{
    int n = arr.size();
    // this question is similar to above partition equal subset sum, but in this case, there is no equal subset sum
    // so we need to find the point where the sum of subsets is equal to the sum of the whole set
    // and difference is minimum
    // we can understand one thing from the above solution is that the last of row of matrix had all the values
    // of whether any target value has the subset sum equal to target
    // it has values from 0 to target, and we have answer is true or false
    // so we can understand that we need to check for the answer in the middle of that column

    // so we know the sum of both sets- that is: s1+s2=sum(s)
    // also if sum1=sum of(s1) and if dp[n-1][sum1] is true
    // then dp[n-1][s-sum1] is also true
    // so we just need to minimize this difference
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    vector<vector<bool>> dp(n, vector<bool>(sum + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    if (arr[0] <= sum)
        dp[0][arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            bool notTake = dp[i - 1][j];
            bool take = false;
            if (arr[i] <= j)
                take = dp[i - 1][j - arr[i]];
            dp[i][j] = take || notTake;
        }
    }

    int mn = INT_MAX;
    for (int i = 0; i <= sum / 2; i++)
        if (dp[n - 1][i])
            mn = min(mn, abs((sum - i) - i));

    return mn;
}

// space optimization
int partitonSet(vector<int> &arr)
{
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    vector<bool> prev(sum + 1, 0), cur(sum + 1, 0);
    prev[0] = true;
    if (arr[0] <= sum)
        prev[arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            bool notTake = prev[j];
            bool take = false;
            if (arr[i] <= j)
                take = prev[j - arr[i]];
            cur[j] = take || notTake;
        }
        prev = cur;
    }

    int mn = INT_MAX;
    for (int i = 0; i <= sum / 2; i++)
        if (prev[i])
            mn = min(mn, abs((sum - i) - i));

    return mn;
}
int main()
{
}