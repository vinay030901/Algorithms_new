/* the question says
we have a frog and we need to jump from position to N
so every jump has an energy, we need to find the path which has the minimum energy
so we will try to find minimal path
we can jump by 1 or 2

the cost of every jump is the difference between the energies
greedy solution will not work here

how to write the recursion:
1. express the problem on indices
2. do all stuffs on that index
3. take the minimal of all the stuffs
*/

#include <bits/stdc++.h>
using namespace std;
int frogJumpMemoize(vector<int> energy, int n, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int left = frogJumpMemoize(energy, n - 1, dp) + abs(energy[n] - energy[n - 1]);
    int right = INT_MAX;
    if (n > 1)
        right = frogJumpMemoize(energy, n - 2, dp) + abs(energy[n] - energy[n - 2]);
    return dp[n] = min(left, right);
}
int frogJump(vector<int> energy, int n)
{
    vector<int> dp(n + 1, -1);
    return frogJumpMemoize(energy, n - 1, dp);
}

/*now, we will try to solve it using bottom up approach*/
int frogJumpBottomUp(vector<int> energy, int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int left = dp[i - 1] + abs(energy[i] - energy[i - 1]);
        int right = INT_MAX;
        if (i > 1)
            right = dp[i - 2] + abs(energy[i] - energy[i - 2]);
        dp[i] = min(left, right);
    }
    return dp[n - 1];
}

// space optimization case
int frogJumpSpaceOptimization(vector<int> energy, int n)
{
    int prev1 = 0, prev2 = 0;
    for (int i = 1; i <= n; i++)

    {
        int left = prev1 + abs(energy[i] - energy[i - 1]);
        int right = INT_MAX;
        if (i > 1)
            right = prev2 + abs(energy[i] - energy[i - 2]);
        int curr = min(prev1, prev2);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int main()
{
    int n;
    cin >> n;
    vector<int> energy(n);
    for (int i = 0; i < n; i++)
        cin >> energy[i];
    cout << frogJump(energy, n) << endl;
}
