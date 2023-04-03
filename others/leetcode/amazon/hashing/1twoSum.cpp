/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]*/

#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int> &arr, int t)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        if (mp.find(t - arr[i]) != mp.end())
            return {i, mp[t - arr[i]]};
        else
            mp[arr[i]] = i;
    }
    return {};
}
int main()
{
}