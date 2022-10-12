/*
Given an array of integers arr, sort the array by performing a series of pancake flips.

In one pancake flip we do the following steps:

Choose an integer k where 1 <= k <= arr.length.
Reverse the sub-array arr[0...k-1] (0-indexed).
For example, if arr = [3,2,1,4] and we performed a pancake flip choosing k = 3, we reverse the sub-array [3,2,1], so arr = [1,2,3,4]
after the pancake flip at k = 3.

Return an array of the k-values corresponding to a sequence of pancake flips that sort arr. Any valid answer that sorts the
array within 10 * arr.length flips will be judged as correct.

Example 1:

Input: arr = [3,2,4,1]
Output: [4,2,4,3]
Explanation:
We perform 4 pancake flips, with k values 4, 2, 4, and 3.
Starting state: arr = [3, 2, 4, 1]
After 1st flip (k = 4): arr = [1, 4, 2, 3]
After 2nd flip (k = 2): arr = [4, 1, 2, 3]
After 3rd flip (k = 4): arr = [3, 2, 1, 4]
After 4th flip (k = 3): arr = [1, 2, 3, 4], which is sorted.
Example 2:

Input: arr = [1,2,3]
Output: []
Explanation: The input is already sorted, so there is no need to flip anything.
Note that other answers, such as [3, 3], would also be accepted.
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> pancakeSort(vector<int> &arr)
{
    /*
    Explanation-- 
    Find the index i of the next maximum number x.
    Reverse i + 1 numbers, so that the x will be at A[0]
    Reverse x numbers, so that x will be at A[x - 1].
    Repeat this process N times.*/
    vector<int> res;
    int size = arr.size();
    while (size > 2)
    {
        int mxIndex = 0, mxNum = INT_MIN;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] > mxNum)
            {
                mxIndex = i;
                mxNum = arr[i];
            }
        }
        res.push_back(mxIndex + 1);
        res.push_back(size);
        reverse(arr.begin(), arr.begin() + mxIndex + 1);
        reverse(arr.begin(), arr.begin() + size);

        size--;
    }
    if (size == 2 && arr[0] > arr[1])
        res.push_back(2);
    return res;
}
int main()
{
}