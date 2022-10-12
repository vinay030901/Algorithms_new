/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array.

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2*/
#include <bits/stdc++.h>
using namespace std;

// this works in linear time and constant space
// we will traverse the array and have a ind variable to count the values
// if the next value is same, we will increase its value and if not, we will decrease it
// if after decreasing, it becomes zero, we will change the mx variable to that value
int majorityElement(vector<int> &arr)
{
    int n = arr.size();
    int mx = arr[0], ind = 1;
    for (int i = 1; i < n; i++)
    {
        if (mx != arr[i])
        {
            ind--;
            if (ind == 0)
            {
                mx = arr[i];
                ind = 1;
            }
        }
        else
            ind++;
    }
    return mx;
}

// simple hashing approach
int majorityElement(vector<int> &arr)
{
    unordered_map<int, int> mp;
    int n = arr.size();
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
        if (mp[arr[i]] > n / 2)
            return arr[i];
    }
    return -1;
}
int main()
{
}