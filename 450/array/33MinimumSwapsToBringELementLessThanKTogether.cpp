/*
Given an array of n positive integers and a number k. Find the minimum number of swaps required to bring all
the numbers less than or equal to k together.


Input:  arr[] = {2, 1, 5, 6, 3}, k = 3
Output: 1

Explanation:
To bring elements 2, 1, 3 together, swap
element '5' with '3' such that final array
will be-
arr[] = {2, 1, 3, 6, 5}

Input:  arr[] = {2, 7, 9, 5, 8, 7, 4}, k = 5
Output: 2*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // int arr[] = {2, 7, 9, 5, 8, 7, 4}, k = 5;
    // int arr[] = {2, 1, 5, 6, 3}, k = 3;
    int arr[] = {4, 11, 6, 5, 11, 20, 19, 14, 14, 2, 9, 20, 11, 11, 15, 1, 7, 12, 19, 9};
    int k = 14;
    int n = sizeof(arr) / sizeof(arr[0]);

    // here what we need to do is find that window which has the least of non favourable values, or values that are greater
    // than k. Therefore first we find the elements which are less than k, that would be our window size
    /*now we traverse the array and check for every window, so when we change the window, we will check if the first element
    of that window was greater than k, if it is we will decrease the no of non favorable, and then we check the same for
    the new element we cover in our window now, if it is then we will increase the non favorable count

    we will keep track of lowest value of non favorable, which would be our answer*/
    int count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] <= k)
            count++; // counting the no of elements less than k, our window size
    int nonFav = 0;
    for (int i = 0; i < count; i++)
        if (arr[i] > k)
            nonFav++; // no. of non favorable in our first window

    int ans = nonFav;
    for (int i = 0, j = count; j < n; i++, j++)
    {
        if (arr[i] > k) // if the first element of window is greater than k, so count of nonFav decrease, as we are moving 
        // the window
            nonFav--;
        if (arr[j] > k)
            nonFav++;
        ans = min(nonFav, ans);
    }
    cout << ans;
}