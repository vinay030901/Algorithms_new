/*
Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.
Example 1:

Input:
K = 3
arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
Output: 1 2 3 4 5 6 7 8 9
Explanation:Above test case has 3 sorted
arrays of size 3, 3, 3
arr[][] = [[1, 2, 3],[4, 5, 6],
[7, 8, 9]]
The merged list will be
[1, 2, 3, 4, 5, 6, 7, 8, 9].
Example 2:

Input:
K = 4
arr[][]={{1,2,3,4},{2,2,3,4},
         {5,5,6,6},{7,8,9,9}}
Output:
1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9
Explanation: Above test case has 4 sorted
arrays of size 4, 4, 4, 4
arr[][] = [[1, 2, 2, 2], [3, 3, 4, 4],
[5, 5, 6, 6], [7, 8, 9, 9 ]]
The merged list will be
[1, 2, 2, 2, 3, 3, 4, 4, 5, 5,
6, 6, 7, 8, 9, 9].*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> pp;
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    vector<int> ans;
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    for (int i = 0; i < arr.size(); i++)
        pq.push({arr[i][0], {i, 0}});
    while (!pq.empty())
    {
        auto val = pq.top().first;
        auto ind = pq.top().second;
        ans.push_back(val);
        pq.pop();
        if (ind.second + 1 < arr[ind.first].size())
            pq.push({arr[ind.first][ind.second + 1], {ind.first, ind.second + 1}});
    }
    return ans;
}
int main()
{

    return 0;
}