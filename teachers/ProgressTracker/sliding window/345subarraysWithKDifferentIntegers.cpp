/*Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.



Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].


Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i], k <= nums.length*/
#include <bits/stdc++.h>
using namespace std;
/*to solve this questions, we need to learn the popular technique for this

we need to see this in the form of at most k distinct integers, then this problem will become simple*/
int atmost(vector<int> arr, int k)
{
    int count = 0, left = 0, right = 0, n = arr.size();
    unordered_map<int, int> mp;
    while (right < n)
    {
        if (!mp[arr[right]]++)
            k--;
        while (k < 0)
        {
            --mp[arr[left]];
            if (mp[arr[left++]] == 0)
                k++;
        }
        count += right - left + 1;
        right++;
    }
    return count;
}
int subarraysWithKDistinct(vector<int> &arr, int k)
{
    return atmost(arr, k) - atmost(arr, k - 1);
}
int main()
{
    return 0;
}