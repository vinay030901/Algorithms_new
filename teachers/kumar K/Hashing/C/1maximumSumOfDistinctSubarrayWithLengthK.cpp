/*
You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

The length of the subarray is k, and
All the elements of the subarray are distinct.
Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

A subarray is a contiguous non-empty sequence of elements within an array.



Example 1:

Input: nums = [1,5,4,2,9,9,9], k = 3
Output: 15
Explanation: The subarrays of nums with length 3 are:
- [1,5,4] which meets the requirements and has a sum of 10.
- [5,4,2] which meets the requirements and has a sum of 11.
- [4,2,9] which meets the requirements and has a sum of 15.
- [2,9,9] which does not meet the requirements because the element 9 is repeated.
- [9,9,9] which does not meet the requirements because the element 9 is repeated.
We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
Example 2:

Input: nums = [4,4,4], k = 3
Output: 0
Explanation: The subarrays of nums with length 3 are:
- [4,4,4] which does not meet the requirements because the element 4 is repeated.
We return 0 because no subarrays meet the conditions.


Constraints:

1 <= k <= nums.length <= 105
1 <= nums[i] <= 105*/
/*we solved this question using the sliding window method where we keep track of the number of element using an unordered map and then whenever the arr[right] repeats, we will keep increasing the left and decreasing the frequency of arr[left]
in this way, we will get to the answer
the code is mostly self explainatory*/
#include <bits/stdc++.h>
using namespace std;
long long maximumSubarraySum(vector<int> &arr, int k)
{
    unordered_map<int, int> mp;
    long long sum = 0, left = 0, right = 0, n = arr.size(), mx = 0;
    while (right < n)
    {
        mp[arr[right]]++;
        while (left < right && mp[arr[right]] > 1)
        {
            mp[arr[left]]--;
            sum -= arr[left++];
        }
        sum += arr[right];
        if (right - left + 1 == k)
        {
            mx = max(mx, sum);
            mp[arr[left]]--;
            sum -= arr[left++];
        }
        right++;
    }
    return mx;
}