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
-109 <= nums[i] <= 109
 */
#include <bits/stdc++.h>
using namespace std;
int longestConsecutive(vector<int> &arr)
{
    unordered_set<int> st(arr.begin(), arr.end());
    int mx = 0;
    for (auto it : arr)
    {
        if (st.find(it + 1) == st.end())
        {
            int cnt = 0;
            while (st.find(it--) != st.end())
                cnt++;
            mx = max(cnt, mx);
        }
    }
    return mx;
}
class Solution
{
public:
    unordered_map<int, int> par, size;
    void make(int a)
    {
        par[a] = a;
        size[a] = 1;
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
            if (size[y] > size[x])
                swap(x, y);
            par[y] = x;
            size[x] += size[y];
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
            mx = max(mx, size[it]);
        return mx;
    }
};