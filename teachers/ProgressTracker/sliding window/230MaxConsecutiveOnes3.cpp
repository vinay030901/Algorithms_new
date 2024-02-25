/*Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.


Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length*/
#include <bits/stdc++.h>
using namespace std;
int longestOnes(vector<int> &arr, int k)
{
    int cnt = 0, left = 0, right = 0, n = arr.size(), mx = 0;
    while (right < n)
    {
        if (arr[right] == 0)
        {
            cnt++;
            while (left <= right && cnt > k)
            {
                if (arr[left] == 0)
                    cnt--;
                left++;
            }
        }
        if (cnt <= k)
        {
            mx = max(mx, right - left + 1);
        }
        right++;
    }
    return mx;
}
int main()
{
    // Your code here
    return 0;
}