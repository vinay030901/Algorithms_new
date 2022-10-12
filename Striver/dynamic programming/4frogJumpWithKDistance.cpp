/*this question is the advancement of the above question
since we can make k jumps in this case rather than 1 or 2 jumps in the previous question

to do this, we just need to make a look when we are comparing the values rather than two variables
in this way we can find the minimum of those values and find the answer*/
#include <bits/stdc++.h>
using namespace std;
int frogJumpMemoize(vector<int> energy, int n, vector<int> &dp, int k)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int mn = INT_MAX;
    for (int i = 1; i <= k; i++)
        if (n >= i)
            mn = min(mn, frogJumpMemoize(energy, n - i, dp, k) + abs(energy[n] - energy[n - i]));
    return dp[n] = mn;
}
int frogJump(vector<int> energy, int n, int k)
{
    vector<int> dp(n + 1, -1);
    return frogJumpMemoize(energy, n - 1, dp, k);
}

// bottom up approach for this
int frogJumpBottomUp(vector<int> energy, int n, int k)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int mn = INT_MAX;
        for (int j = 1; j <= k; j++)
            if (i >= j)
                mn = min(mn, dp[i - j] + abs(energy[i] - energy[i - j]));
        dp[i] = mn;
    }
    return dp[n - 1];
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> energy(n);
    for (int i = 0; i < n; i++)
        cin >> energy[i];
    cout << frogJump(energy, n - 1, k) << endl;
    cout << frogJumpBottomUp(energy, n - 1, k) << endl;
}
