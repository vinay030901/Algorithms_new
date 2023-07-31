#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
void permutation(vector<int> &arr, int l, int r)
{
    if (l == r)
    {
        ans.push_back(arr);
        return;
    }
    for (int i = l; i <= r; i++)
    {
        swap(arr[i], arr[l]);
        permutation(arr, l + 1, r);
        swap(arr[i], arr[l]);
    }
}
vector<vector<int>> permute(vector<int> &arr)
{
    permutation(arr, 0, arr.size() - 1);
    return ans;
}