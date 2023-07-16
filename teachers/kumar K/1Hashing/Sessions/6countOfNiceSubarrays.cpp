/*
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.
Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There is no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16*/
#include <bits/stdc++.h>
using namespace std;
// here we are calculating all the subarrays which atmost k odd elements
// then we decrease the k-1 odd element count from it, to get the number of subarrays with k odd element
int most(vector<int> &arr, int k)
{
    int ans = 0, left = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        k -= arr[i] % 2;
        while (left <= i && k < 0)
            k += arr[left++] % 2;
        ans += i - left + 1;
    }
    return ans;
}
int numberOfSubarrays(vector<int> &nums, int k)
{
    return most(nums, k) - most(nums, k - 1);
}
int main()
{
    return 0;
}