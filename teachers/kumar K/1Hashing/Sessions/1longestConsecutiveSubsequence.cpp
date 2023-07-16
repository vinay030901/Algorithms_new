/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.
Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109*/
#include <bits/stdc++.h>
using namespace std;
// solution using unordered set
int longestConsecutive(vector<int> &arr)
{
    unordered_set<int> s(arr.begin(), arr.end());
    int mx = 0;
    for (auto it : arr)
    {
        if (s.count(it - 1))
            continue;
        int j = 1;
        while (s.count(it + j))
            j++;
        mx = max(mx, j);
    }
    return mx;
}

// solution using union find
unordered_map<int, int> par;
unordered_map<int, int> element_size;
void make(int a)
{
    par[a] = a;
    element_size[a] = 1;
}
int findPar(int a)
{
    if (par[a] == a)
        return a;
    return par[a] = findPar(par[a]);
}
void Union(int x, int y)
{
    x = findPar(x);
    y = findPar(y);
    if (x != y)
    {
        if (element_size[y] > element_size[x])
            swap(x, y);
        par[y] = x;
        element_size[x] += element_size[y];
    }
}
int longestConsecutive(vector<int> &arr)
{
    for (auto it : arr)
        make(it);
    for (auto it : arr)
        if (par.count(it + 1))
            Union(it, it + 1);
    int mx = 0;
    for (auto it : arr)
        mx = max(mx, element_size[it]);
    return mx;
}
int main()
{

    return 0;
}