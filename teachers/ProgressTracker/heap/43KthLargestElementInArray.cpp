#include <bits/stdc++.h>
using namespace std;
int findKthLargest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> mn;
    for (auto it : arr)
    {
        mn.push(it);
        if (mn.size() > k)
            mn.pop();
    }
    return mn.top();
}