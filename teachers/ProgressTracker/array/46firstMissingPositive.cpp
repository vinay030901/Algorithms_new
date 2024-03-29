#include <bits/stdc++.h>
using namespace std;
// using extra space
int firstMissingPositive(vector<int> &arr)
{
    unordered_map<int, int> mp;
    int n = arr.size();
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;
    for (int i = 1; i <= n; i++)
        if (mp.find(i) == mp.end())
            return i;
    return n + 1;
}

// wihtout using extra space
int firstMissingPositive(vector<int> &arr)
{
    // https://leetcode.com/problems/first-missing-positive/discuss/17071/My-short-c%2B%2B-solution-O(1)-space-and-O(n)-time
    // here we are swapping the values back to its place
    int n = arr.size();
    for (int i = 0; i < n; i++)
        while (arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i])
            swap(arr[arr[i] - 1], arr[i]);
    for (int i = 0; i < n; i++)
        if (arr[i] != (i + 1))
            return i + 1;
    return n + 1;
}