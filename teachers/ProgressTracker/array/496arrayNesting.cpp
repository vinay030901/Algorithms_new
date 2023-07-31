#include <bits/stdc++.h>
using namespace std;
int arrayNesting(vector<int> &arr)
{
    vector<int> vis(arr.size(), 0);
    if (arr.size() == 0)
        return 0;
    int mx = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (vis[i] == 0)
        {
            int cnt = 0, curr = i;
            while (vis[curr] == 0)
            {
                vis[curr] = 1;
                cnt++;
                curr = arr[curr];
            }
            mx = max(cnt, mx);
        }
    }
    return mx;
}