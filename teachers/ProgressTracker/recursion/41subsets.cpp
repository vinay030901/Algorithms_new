#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
void fun(int ind, vector<int> &arr, vector<int> &v, int n)
{
    if (ind == n)
    {
        ans.push_back(v);
        return;
    }
    v.push_back(arr[ind]);
    fun(ind + 1, arr, v, n);
    v.pop_back();
    fun(ind + 1, arr, v, n);
}
vector<vector<int>> subsets(vector<int> &arr)
{
    vector<int> v;
    fun(0, arr, v, arr.size());
    return ans;
}
vector<vector<int>> subsetsq(vector<int> &arr)
{
    int n = arr.size();
    int subsetsCount = 1 << n;
    vector<vector<int>> ans;
    for (int i = 0; i < subsetsCount; i++)
    {
        vector<int> v;
        for (int j = 0; j < j; j++)
        {
            if (i & (1 << j))
                v.push_back(arr[j]);
        }
        ans.push_back(v);
    }
    return ans;
}