/*
Given an array of size n, find all elements in array that appear more than n/k times.
For example, if the input arrays is {3, 1, 2, 2, 1, 2, 3, 3} and k is 4, then the output should be [2, 3].
Note that size of array is 8 (or n = 8), so we need to find all elements that appear more than 2 (or 8/4) times.
There are two elements that appear more than two times, 2 and 3. */

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {3, 1, 2, 2, 1, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    // we can do this in O(N) time and O(N) space
    // other process include doing it in O(n^2) time using brute force and O(NlogN) time using sorting.
    // first using O(n) space is we can map a map and count the frequency of every element in the array
    // and print the element having more than k times.
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;
    int p = n / k;
    cout << "using O(n) space and mp: ";
    for (auto it = mp.begin(); it != mp.end(); it++)
        if (it->second > p)
            cout << it->first << " ";
}