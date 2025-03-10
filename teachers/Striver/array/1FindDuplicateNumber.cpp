/* find the duplicate number in range n+1*/
/*Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.



Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [3,3,3,3,3]
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
int main()
{
    int arr1[] = {2, 5, 6, 9, 3, 8, 9, 7, 1};
    int arr[] = {2, 5, 9, 5, 3, 8, 6, 7, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    // hashing approach
    /*int map[n+1]={0};
    for(int i=0;i<n+1;i++)
    {
        map[arr[i]]++;
    }
    for(int i=0;i<n+1;i++)
    {
        if(map[i]>1)
            cout<<i<<endl;
    }*/
    /*we can use the hashing approach but it will take O(n) space, so instead of it, we will go for cyclic linkedlist approach
    we are going to use tortoise and hare algorithm, in which we will traverse with two pointers, and speed of them would be 2 and 1,
    the position at which both will meet will be the repeating number*/
    int fast = arr[0];
    int slow = arr[0];
    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);
    fast = arr[0];
    while (slow != fast)
    {
        fast = arr[fast];
        slow = arr[slow];
    }
    cout << slow << endl;
}