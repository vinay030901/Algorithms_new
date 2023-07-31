#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
void recur(vector<int> &arr, int sum, int n, vector<int> &v)
{
    if (sum < 0 || n < 0)
        return;
    if (sum == 0)
    {
        ans.push_back(v);
        return;
    }
    if (arr[n] <= sum)
    {
        v.push_back(arr[n]);
        recur(arr, sum - arr[n], n, v);
        v.pop_back();
    }
    recur(arr, sum, n - 1, v);
}
vector<vector<int>> combinationSum(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<int> v;
    recur(arr, target, n - 1, v);
    return ans;
}