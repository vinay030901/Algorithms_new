// https://algo.monster/problems/sliding_window_maximum
#include <bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int> &arr, int k)
{
    vector<int> res;
    deque<int> dq;
    int j = 0, i = 0, n = arr.size();
    for (int i = 0; i < n; i++)
    {
        while (!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();
        dq.push_back(i);
        if (dq.front() == i - k)
            dq.pop_front();
        if (i >= k - 1)
            res.push_back(arr[dq.front()]);
    }
    return res;
}
int main()
{
}