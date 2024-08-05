#include <bits/stdc++.h>
using namespace std;

int fun(int n, int s, int w, int k, vector<int> &arr, int i, vector<int> &dp)
{
    if (i >= n)
        return 0;

    if (dp[i] != -1)
        return dp[i];
    int sprinkle = INT_MAX;
    if (i + k - 1 < n)
    {
        sprinkle = w + fun(n, s, w, k, arr, i + k);
    }
    int swapping = INT_MAX;
    if (i + 1 < n)
    {
        swap(arr[i], arr[i + 1]);
        swapping = k + fun(n, s, w, k, arr, i + 1, dp);
        swap(arr[i], arr[i + 1]);
    }
    int water = arr[i] + fun(n, s, w, k, arr, i + 1, dp);
    return dp[i] = min(water, min(sprinkle, swapping));
}
int plantGrowingContest(int n, int k, int w, int s, vector<int> &arr, vector<int> &dp)
{
    return fun(n, s, w, k, arr, 0, dp);
}
int main()
{
    int n, k, w, s;
    cin >> n >> k >> w >> s;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> dp(n + 1, -1);
    cout << plantGrowingContest(n, k, w, s, arr, dp);
}