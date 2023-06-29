/*You are given an array Arr of size N. You have to find the K-th largest sum of contiguous subarray within the array elements.



Example 1:

Input:
N = 3
K = 2
Arr = {3,2,1}
Output:
5
Explanation:
The different subarray sums we can get from the array
are = {6,5,3,2,1}. Where 5 is the 2nd largest.


Example 2:

Input:
N = 4
K = 3
Arr = {2,6,4,1}
Output:
11
Explanation:
The different subarray sums we can get from the array
are = {13,12,11,10,8,6,5,4,2,1}. Where 11 is the 3rd largest.*/
/*
The basic idea behind the Prefix Sum and Sorting approach is to create a prefix sum array and use it to calculate all possible subarray sums. The subarray sums are then sorted in decreasing order using the sort() function. Finally, the K-th largest sum of contiguous subarray is returned from the sorted vector of subarray sums.
Follow the Steps to implement the approach:

Create a prefix sum array of the given array.
Create a vector to store all possible subarray sums by subtracting prefix sums.
Sort the vector of subarray sums in decreasing order using the sort() function.
Return the K-th largest sum of contiguous subarray from the sorted vector of subarray sums.
Below is the implementation of the above approach:*/
#include <bits/stdc++.h>
using namespace std;
int kthLargest(vector<int> &arr, int n, int K)
{
    vector<int> prefixSum(n + 1);
    prefixSum[0] = 0;
    for (int i = 1; i <= n; i++)
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];

    // create a vector to store all possible subarray sums
    vector<int> subarrarySums;
    for (int i = 0; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            subarrarySums.push_back(prefixSum[j] - prefixSum[i]);
            cout << subarrarySums.back() << " ";
        }
    sort(subarrarySums.begin(), subarrarySums.end(), greater<int>());
    return subarrarySums[K - 1];
}
int main()
{

    return 0;
}