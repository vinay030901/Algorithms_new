/*
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be
unique and you may return the result in any order.



Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.*/
#include <bits/stdc++.h>
using namespace std;
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    set<int> s1, s2;
    vector<int> ans;
    for (auto it : nums1)
        s1.insert(it);
    for (auto it : nums2)
        s2.insert(it);
    for (auto it : s1)
        if (s2.find(it) != s2.end())
            ans.push_back(it);
    return ans;
}
int main()
{
}