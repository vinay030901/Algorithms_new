/*
Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.


Example 1:

Input: 
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated 
into ascending order.
Example 2:

Input: 
N = 3
arr[] = {0 1 0}
Output:
0 0 1
Explanation:
0s 1s and 2s are segregated 
into ascending order.

Your Task:
You don't need to read input or print anything. Your task is to complete the function sort012() that takes an array arr and N as input parameters and sorts the array in-place.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

*/

#include<bits/stdc++.h>
using namespace std;
void sort012(int a[], int n)
    {
        // we need to use dutch national flag algo here
        int low=0,med=0,high=n-1;
        while(med<=high)
        {
            if(a[med]==0)
                swap(a[med++],a[low++]);
            else if(a[med]==2)
                swap(a[med],a[high--]);
            else med++;
        }
    }