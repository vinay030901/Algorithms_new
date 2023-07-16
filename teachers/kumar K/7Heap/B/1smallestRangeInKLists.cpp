/*
You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation:
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Example 2:

Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]*/
#include <bits/stdc++.h>
using namespace std;
struct Data
{
    int value, i, j;
    Data(int v1, int v2, int v3) : value(v1), i(v2), j(v3) {}
};
struct Compare
{
    bool operator()(Data a, Data b)
    {
        return a.value > b.value;
    }
};

vector<int> smallestRange(vector<vector<int>> &arr)
{
    priority_queue<Data, vector<Data>, Compare> pq;
    int mx = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        pq.push(Data(arr[i][0], i, 0));
        mx = max(mx, arr[i][0]);
    }
    int start = INT_MIN, end = INT_MAX, range = INT_MAX;
    while (!pq.empty())
    {
        int mn = pq.top().value;
        int row = pq.top().i;
        int col = pq.top().j;
        pq.pop();
        if (range > mx - mn + 1)
        {
            range = mx - mn + 1;
            start = mn;
            end = mx;
        }
        if (col == arr[row].size() - 1)
            break;
        pq.push(Data(arr[row][col + 1], row, col + 1));
        mx = max(mx, arr[row][col + 1]);
    }
    vector<int> ans;
    ans.push_back(start);
    ans.push_back(end);
    return ans;
}
int main()
{

    return 0;
}