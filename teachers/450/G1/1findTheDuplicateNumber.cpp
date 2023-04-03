/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.


Follow up:

How can we prove that at least one duplicate number must exist in nums?
Can you solve the problem in linear runtime complexity?*/
#include <bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int> &arr)
{
    // so we used the tortoise hare approach here
    // we have two counters, fast and slow, fast is arr[arr[ind]] while slow is arr[ind]
    // we will move both of them until they are same, means they have encountered the same number
    // then we will linearly traverse with both of them now and when thet meet, that's our repeating number
    int n = arr.size();
    int fast = arr[0], slow = arr[0];
    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);
    fast = arr[0];
    while (fast != slow)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}
int main()
{
    vector<int> arr = {1, 2, 3, 3, 4};
    // we can use O(n^2) approach but question says to do this in linear time, we won't use map because question says
    // to do this in constant space, so will use tortoise hare algorithm
    cout << findDuplicate(arr);
}