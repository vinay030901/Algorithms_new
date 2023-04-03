#include <bits/stdc++.h>
using namespace std;
vector<string> ans;
void fun(string str, int l, int r)
{
    if (l >= r)
    {
        ans.push_back(str);
        return;
    }
    for (int i = l; i <= r; i++)
    {
        swap(str[i], str[l]);
        fun(str, l + 1, r);
        swap(str[l], str[i]);
    }
}
vector<string> find_permutation(string str)
{
    fun(str, 0, str.size() - 1);
    return ans;
}

void recurPermute(vector<int> &ds, vector<int> &arr, vector<vector<int>> &ans, int freq[])
{
    if (ds.size() == arr.size())
    {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (!freq[i])
        {
            ds.push_back(arr[i]);
            freq[i] = 1;
            recurPermute(ds, arr, ans, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[arr.size()] = {0};
    recurPermute(ds, arr, ans, freq);
    return ans;
}
int main()
{
}