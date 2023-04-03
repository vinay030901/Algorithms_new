/*
Given two arrays: arr1[0..m-1] and arr2[0..n-1]. Find whether arr2[] is a subset of arr1[] or not. Both the arrays are not in sorted order. It may be assumed that elements in both array are distinct.

Examples:

Input: arr1[] = {11, 1, 13, 21, 3, 7}, arr2[] = {11, 3, 7, 1}
Output: arr2[] is a subset of arr1[]

Input: arr1[] = {1, 2, 3, 4, 5, 6}, arr2[] = {1, 2, 4}
Output: arr2[] is a subset of arr1[]

Input: arr1[] = {10, 5, 2, 23, 19}, arr2[] = {19, 5, 3}
Output: arr2[] is not a subset of arr1[] */
#include <bits/stdc++.h>
using namespace std;
bool fun(int *arr1, int *arr2, int n, int m)
{
    if (n < m)
        return false;
    sort(arr1, arr1 + n); // sorting both the arrays
    sort(arr2, arr2 + m);
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j]) // if arr1 element is smaller, then we will move on
            i++;
        else if (arr1[i] == arr2[j]) // if we find equal element, then increase both of them
        {
            i++;
            j++;
        }
        else
            return false; // if we reach this position, it means we weren't able to find any element equal to our array
        // so we will return false
    }
    if (j == m)
        return true; // if j and length of smaller array is equal, that means arr2 is subset
    else
        return false;
}
bool isSubset(int *arr1, int *arr2, int n, int m)
{
    unordered_set<int> s;
    for (int i = 0; i <= n; i++)
        s.insert(arr1[i]);
    for (int i = 0; i < m; i++)
    {
        if (s.find(arr2[i]) == s.end()) // if we can't find any element equal to arr2[i], then return false
            return false;
    }
    return true;
}
int main()
{
    int arr1[] = {11, 1, 13, 21, 3, 7}, arr2[] = {11, 3, 7, 1};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    // to check if arr2 is subset of arr1, we can just put all the elements of arr1 in a set,
    // then one by one check using arr2 if the element is avaiable or not, if all the elements are available,
    // the answer is true, otherwise we will return false;
    cout << "using hashing: \n";
    if (isSubset(arr1, arr2, n, m) == true)
        cout << "arr2 is a subset of arr1\n";
    else
        cout << "arr2 is not a subset of arr1\n";

    // but above method doesn't handle the duplicate cases, if arr2 has two same elements, then it will still
    // give true which is wrong
    /*so, to handle this we can do sorting and merging type of process, where we wil first sort the elements and
    then use merge sort type process where we will count the equal elements*/
    cout << "using sorting: \n";
    if (fun(arr1, arr2, n, m))
        cout << "arr2 is a subset of arr1\n";
    else
        cout << "arr2 is not a subset of arr1\n";
}