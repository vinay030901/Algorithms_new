#include <bits/stdc++.h>
using namespace std;
int subarraySum(vector<int> &arr, int k)
{
    int cnt = 0, sum = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    for (auto it : arr)
    {
        sum += it;
        if (mp.find(sum - k) != mp.end())
            cnt += mp[sum - k];
        mp[sum]++;
    }
    return cnt;
}