/*
Given an array of integers, and a number ‘sum’, find the number of pairs of integers in the array whose sum is equal to ‘sum’.

Examples:

Input  :  arr[] = {1, 5, 7, -1},
          sum = 6
Output :  2
Pairs with sum 6 are (1, 5) and (7, -1)

Input  :  arr[] = {1, 5, 7, -1, 5},
          sum = 6
Output :  3
Pairs with sum 6 are (1, 5), (7, -1) &
                     (1, 5)

Input  :  arr[] = {1, 1, 1, 1},
          sum = 2
Output :  6
There are 3! pairs with sum 2.

Input  :  arr[] = {10, 12, 10, 15, -1, 7, 6,
                   5, 4, 2, 1, 1, 1},
          sum = 11
Output :  9
Expected time complexity O(n)
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {10, 12, 10, 15, -1, 7, 6, 5, 4, 2, 1, 1, 1};
    int sum = 11;
    int count = 0;
    int n = sizeof(arr) / sizeof(arr[0]);
    // we need to find the pairs, this could be easily done using brute force, but to do it in linear time
    // we can use map for this process, we will just find if there is a pair for the given value and sum the count of it
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(sum - arr[i]) != mp.end())
            count += mp[sum - arr[i]];
        mp[arr[i]]++;
    }
    cout << count;
}