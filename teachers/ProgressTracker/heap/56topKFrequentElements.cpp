#include <bits/stdc++.h>
using namespace std;
vector<int> topKFrequent(vector<int> &nums, int k)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    unordered_map<int, int> mp;
    for (auto it : nums)
        mp[it]++;
    for (auto it : mp)
    {
        pq.push({it.second, it.first});
        if (pq.size() > k)
            pq.pop();
    }
    vector<int> ans;
    while (k--)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}