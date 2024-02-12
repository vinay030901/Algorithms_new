/*Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.



Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.


Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.*/
#include <bits/stdc++.h>
using namespace std;
int findMaxLength(vector<int> &arr)
{
    int n = arr.size(), sum = 0, mx = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            arr[i] = -1;
        sum += arr[i];
        if (sum == 0)
            mx = max(mx, i + 1);
        if (mp.find(sum) != mp.end())
            mx = max(mx, i - mp[sum]);
        else
            mp[sum] = i;
    }
    return mx;
}
int main()
{
    // Your code here
    return 0;
}