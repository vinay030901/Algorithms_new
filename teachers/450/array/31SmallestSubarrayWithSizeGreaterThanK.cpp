/*
Given an array of integers and a number x, find the smallest subarray with sum greater than the given value.

Examples:
arr[] = {1, 4, 45, 6, 0, 19}
   x  =  51
Output: 3
Minimum length subarray is {4, 45, 6}

arr[] = {1, 10, 5, 2, 7}
   x  = 9
Output: 1
Minimum length subarray is {10}

arr[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250}
    x = 280
Output: 4
Minimum length subarray is {100, 1, 0, 200}

arr[] = {1, 2, 4}
    x = 8
Output : Not Possible
Whole array sum is smaller than 8.*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2, 3, 1, -4, 5, 1, 2, 3}, x = 7;
    int n = sizeof(arr) / sizeof(arr[0]);
    // one approach, that is the brute force could be check every subarray and if size greater than x, print it.
    // but it will work in O(n^2) time

    // this approach will work in O(n) time in which we are using two pointers
    int i = 0, j = 0, currentSum = 0, count = 0, mn = 0;
    while (i < n)
    {
        while (currentSum < x && i < n)
        {                           // while the current sum is smaller than x, we will increase the length of checking
            currentSum += arr[i++]; // currentSum increasing with count
            count++;
            cout << "count: " << count << endl;
        }
        while (currentSum >= x) // while current sum is greater than the x, we will increase value of j, so that we can find the minimum
        {
            mn = min(mn, count);
            cout << i << " " << j << endl;
            currentSum -= arr[j++]; // decreasing the current value of j by subtracting from arr[j]
            count--;
            cout << "count: " << count << endl; // we are decreasing the count with increase in value of j
        }
    }
    if (count == n && currentSum < x)
        cout << "no such subarray";
    else
        cout << count;
}