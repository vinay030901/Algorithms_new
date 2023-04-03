/*
Given an array of positive integers. We need to make the given array a ‘Palindrome’. The only allowed operation is”merging” (of two adjacent elements). Merging two adjacent elements means replacing them with their sum. The task is to find the minimum number of merge operations required to make the given array a ‘Palindrome’.
To make any array a palindrome, we can simply apply merge operation n-1 times where n is the size of the array (because a single-element array is always palindromic, similar to single-character string). In that case, the size of array will be reduced to 1. But in this problem, we are asked to do it in the minimum number of operations.

Example :

Input : arr[] = {15, 4, 15}
Output : 0
Array is already a palindrome. So we
do not need any merge operation.

Input : arr[] = {1, 4, 5, 1}
Output : 1
We can make given array palindrome with
minimum one merging (merging 4 and 5 to
make 9)

Input : arr[] = {11, 14, 15, 99}
Output : 3
We need to merge all elements to make
a palindrome.*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1, 4, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    /* we will use a two pointer approach here,
    we start the first pointer from start and second from end, then we will compare both the elements under them
     if both of them are equal, then we will increment and decrement the pointers,
    else if (arr[start]>arr[end])-> then it is clear that we need to add value to end, so we add arr[end-1] to arr[end],
    compare arr[start] and arr[end-1]
    else arr[start] will added to next element*/

    int start = 0, end = n - 1, count = 0;
    while (start <= end) // while start is less than end
    {
        if (arr[start] == arr[end]) // if they are equal, we will move on
        {
            start++;
            end--;
        }
        else if (arr[start] < arr[end]) // if start is less, then adding to arr[start]
        {
            arr[start + 1] += arr[start];
            start++;
            count++;
        }
        else // if end is less, then adding to arr[end]
        {
            arr[end - 1] += arr[end];
            end--;
            count++;
        }
    }
    cout << count;
}