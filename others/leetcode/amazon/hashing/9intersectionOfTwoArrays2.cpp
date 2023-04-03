/*
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as
many times as it shows in both arrays and you may return the result in any order.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.


Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000*/
#include <bits/stdc++.h>
using namespace std;
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> m1, m2;
    vector<int> ans;
    for (int i = 0; i < nums1.size(); i++)
        m1[nums1[i]]++;
    for (int i = 0; i < nums2.size(); i++)
        m2[nums2[i]]++;
    for (auto it = m1.begin(); it != m1.end(); it++)
    {
        if (m2.find(it->first) != m2.end())
        {
            int times = min(m1[it->first], m2[it->first]);
            for (int i = 0; i < times; i++)
                ans.push_back(it->first);
        }
    }
    return ans;
}
int main()
{
}