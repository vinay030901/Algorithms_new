/*Given an array arr[] of positive integers of size N. Reverse every sub-array group of size K.

Note: If at any instance, there are no more subarrays of size greater than or equal to K, then reverse the last subarray (irrespective of its size).

Example 1:

Input:
N = 5, K = 3
arr[] = {1,2,3,4,5}
Output: 3 2 1 5 4
Explanation: First group consists of elements
1, 2, 3. Second group consists of 4,5.


Example 2:

Input:
N = 4, K = 3
arr[] = {5,6,8,9}
Output: 8 6 5 9


Your Task:
You don't need to read input or print anything. The task is to complete the function reverseInGroups() which takes the array, N and K as input parameters and modifies the array in-place.



Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)



Constraints:
1 ≤ N, K ≤ 107
1 ≤ A[i] ≤ 1018*/

#include <bits/stdc++.h>
using namespace std;
void reverseInGroups(vector<long long> &arr, int n, int k)
{
    // here I will just reverse the subarray of k size, (n/k) no of times
    // and remaining will be reversed later
    int times = n / k;
    for (int i = 0; i < times; i++)
    {
        int j = k * i;
        int m = j + k - 1;
        while (j < m)
        {
            swap(arr[j++], arr[m--]);
        }
    }
    int i = times * k, j = n - 1;
    while (i < j)
    {
        swap(arr[i++], arr[j--]);
    }
}