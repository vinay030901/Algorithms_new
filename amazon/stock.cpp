#include <bits/stdc++.h>
using namespace std;
int fun(vector<int> &arr, int k)
{
    int ans = -1, cnt = 0, n = arr.size();
    unordered_map<int, int> mp;
    unordered_set<int> s;
    if (n < k)
        return ans;
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
        mp[arr[i]]++;
        s.insert(arr[i]);
    }
    if(s.size() == k)
    ans=max(ans,sum);
    for (int i = k; i < n; i++)
    {
        if (s.size() == k)
        {
            auto it=arr.begin()+(i-k);
            s.erase(it);
            if(s.find(arr[i])==s.end())
            s.insert(arr[i]);
        }

    }
    return ans;
}
int main()
{
    vector<int> v = {1, 2, 4, 4};
    int k = 4;
    cout << fun(v, k) << endl;
}