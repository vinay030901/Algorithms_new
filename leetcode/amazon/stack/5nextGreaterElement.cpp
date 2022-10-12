/*
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of
nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.



Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
Example 2:

Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.*/
#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr2.size();
    stack<int> s;
    unordered_map<int, int> mp;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.empty())
            mp[arr2[i]] = -1;
        else if (s.top() > arr2[i])
            mp[arr2[i]] = s.top();
        else
        {
            while (!s.empty() && s.top() <= arr2[i])
                s.pop();
            if (s.empty())
                mp[arr2[i]] = -1;
            else
                mp[arr2[i]] = s.top();
        }
        s.push(arr2[i]);
    }
    vector<int>ans;
    for(int i=0;i<arr1.size();i++)
    ans.push_back(mp[arr1[i]]);
    return ans;
}
int main()
{
}