/*Given an array arr of distinct elements of size N, the task is to rearrange the elements of the array in a zig-zag fashion so that the converted array should be in the below form:

arr[0] < arr[1]  > arr[2] < arr[3] > arr[4] < . . . . arr[n-2] < arr[n-1] > arr[n].

NOTE: In the mentioned complexity, only a unique solution will exist.

Example 1:

Input:
N = 7
Arr[] = {4, 3, 7, 8, 6, 2, 1}
Output: 3 7 4 8 2 6 1
Explanation: 3 < 7 > 4 < 8 > 2 < 6 > 1
Example 2:

Input:
N = 4
Arr[] = {1, 4, 3, 2}
Output: 1 4 2 3
Explanation: 1 < 4 > 2 < 3
Your Task:
You don't need to read input or print anything. Your task is to complete the function zigZag() which takes the array of integers arr and n as parameters and returns void. You need to modify the array itself.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 105
0 <= Arri <= 106*/

#include <bits/stdc++.h>
using namespace std;
void zigZag(int arr[], int n)
{
    // in this question, we will traverse the array and check if the index is odd or even
    // an even index should be smaller than its next, if it isn't, we will swap them
    // and similarly, an element at odd index should be greater than its next index, so we will swap, if that isn't the case
    for (int i = 0; i < n - 1; i++)
    {
        if ((i & 1) == 0 && arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
        else if ((i & 1) == 1 && arr[i] < arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }
}