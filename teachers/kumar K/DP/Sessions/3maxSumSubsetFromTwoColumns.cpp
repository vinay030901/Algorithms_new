#include <bits/stdc++.h>
using namespace std;
/*
here in this question, we are given two array A and B
and we have to find the max sum of subset of those array
where we need to select only one of the two array element at 1th position and we can't select the adjacent element on the right
lets we have A-> 2 3 4 -8 2
             B-> -5 8 3 1 -4
dp[1]=2
dp[2]=max of all four values(2,3,-5,8)=8
dp[3]=max(4+dp[1],3+dp[1],dp[2])=8
dp[i]=max(dp[i-1],max(a[i],b[i])+dp[i-2])*/
int fun(vector<int> &a, vector<int> &b, int n)
{
    vector<int> dp(n, 0);
    dp[0] = max(a[0], b[0]);
    dp[1] = max(dp[0], max(a[1], b[1]));
    for (int i = 2; i < n; i++)
        dp[i] = max(dp[i - 1], max(a[i], b[i]) + dp[i - 2]);
    return dp[n - 1];
}
int main()
{
    vector<int> a = {2, 3, 4, -8, 2}, b = {-5, 8, 3, 1, -4};
    cout << fun(a, b, a.size()) << endl;
    return 0;
}
