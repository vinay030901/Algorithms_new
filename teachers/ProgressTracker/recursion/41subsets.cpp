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