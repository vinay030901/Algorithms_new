/*Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.



Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true


Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109*/
#include <bits/stdc++.h>
using namespace std;
bool containsDuplicate(vector<int> &arr)
{
    unordered_map<int, int> mp;
    for (auto it : arr)
        if (mp.find(it) != mp.end())
            return true;
        else
            mp[it] = 1;
    return false;
}
int main()
{
    // Your code here
    return 0;
}