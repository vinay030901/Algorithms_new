/*
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.



Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.


Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= k <= min(50, nums.length)*/
#include <bits/stdc++.h>
using namespace std;
bool isValid(vector<int> &arr, int n, int m, int mid)
{
    int students = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
            return false;
        sum += arr[i];

        if (sum > mid)
        {
            students++;
            sum = arr[i];
        }
    }
    if (students > m)
        return false;
    return true;
}
int findPages(vector<int> &arr, int m)
{
    // as the question, we need to find the minimum value for max number of pages the student will read
    // we will use binary search here

    // we can easily say that minimum number of pages student will read is equal to 0 and max is the sum of array here
    // but we have a constraint that one student has to read atleast one book, so we will give him the book with the most value here
    // so atleast one student has to read the book with the most number of pages and therefore we will have our minimum in the range
    // as this maximum value

    // now we will find the find the center and the center value will be the max number of pages a student should read
    // depending on books, we will increase and decrease the value of that center, so that all the book will be in the range

    // for ex we have 10,20,30,40 as the values
    // then the center is 50
    // for s1: 10+20=30<50
    // for s2: 30<50
    // now we have 40 still remaining with us which will another student value, so we will increase the range here
    // now new mid is 50+100/2=75
    // for s1=10+20+30
    // for s2=40
    // so all book are read here and it is completing using two students only
    // now we will go to 62, and then do the same
    // the answer will be same as above here.
    // now we will do this work for 56 here
    // at last we will have 60 as our answer
    int n = arr.size();
    if (n < m)
        return -1;
    int start = *max_element(arr.begin(), arr.end());
    int end = accumulate(arr.begin(), arr.end(), 0);
    int res = -1;
    // here our minimum the least element and the highest is the sum of the values of the array
    while (start <= end)
    {
        // we find the mid of the start and end values and call the function to divide the values
        int mid = start + (end - start) / 2;

        // if the function returns true, that means we can divide the values using the mid and therfore we will decrease the value of end
        // here, to find a more small answer
        if (isValid(arr, n, m, mid) == true)
        {
            res = mid;
            end = mid - 1;
        }
        // if it isnt't true, that means we sent a very small value and therefore we need to increase the value of the mid
        else
            start = mid + 1;
    }
    return res;
}
int main()
{
    // Your code here
    return 0;
}