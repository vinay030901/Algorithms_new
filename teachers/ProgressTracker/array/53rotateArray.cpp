#include <bits/stdc++.h>
using namespace std;
void rotate(vector<int> &arr, int k)
{
    k %= arr.size();
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
}

void rotate(vector<int> &nums, int k)
{
    k %= nums.size();
    std::rotate(nums.begin(), nums.begin() + nums.size() - k, nums.end());
}
