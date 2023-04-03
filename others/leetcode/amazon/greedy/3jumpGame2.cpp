/*
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.



Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2*/
#include <bits/stdc++.h>
using namespace std;
// this question is basically, reach the end of array in minimum number of jumps
// FAST SOLUTION BETTER THAN 90% IN O(N) time
class Solution
{
public:
    int jump(vector<int> &arr)
    {
        // so we are at the first index of the array at the start
        int jumps = 1, maxlen = arr[0], steps = arr[0], n = arr.size();
        if (n == 1)
            return 0;
        // here we will check the maxReach from every step,
        for (int i = 1; i < n; i++)
        {
            if (i == n - 1)
                return jumps;
            // maxreach is max of previous reach and arr[i]+i.
            maxlen = max(arr[i] + i, maxlen);
            steps--; // steps is the count of steps we can take from one point, then we will traverse the array that number of times
            // and find the maxReach from every point, whichever point provide us with the maxReach is taken
            if (steps == 0)
            {
                // in case steps is zero, then we will take a jump
                jumps++;
                if (i >= maxlen)
                    return -1;
                // jumps means change in the value of number of steps
                steps = maxlen - i;
            }
        }
        return -1;
    }
};
int t[10001];
int minSteps(int i, vector<int> &arr)
{
    int n = arr.size();
    if (i >= n - 1) // when we reach the end, we return 0
        return 0;
    if (t[i] != 10006) // memoization part
        return t[i];
    for (int j = 1; j <= arr[i]; j++) // looping over the steps
    {
        t[i] = min(t[i], 1 + minSteps(i + j, arr)); // checking over all the steps and calling the functions
    }
    return t[i];
}
int jump(vector<int> &arr)
{
    // another important method for finding the answer is doing it with the help of memoization
    // if we want to do it using recursion, that means we need to check every step, and or every path
    // to do that, we need to go to every step, then we run a loop of size of the step, and if call our function on every path of it
    for (int &i : t)
    {
        i = 10006;
    }

    int res = minSteps(0, arr);
    return res;
}