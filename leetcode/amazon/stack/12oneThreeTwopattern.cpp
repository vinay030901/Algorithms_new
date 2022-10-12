/*
Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such
that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.



Example 1:

Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.
Example 2:

Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
Example 3:

Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].*/
#include <bits/stdc++.h>
using namespace std;
bool find132pattern(vector<int> &arr)
{
    int n = arr.size();
    vector<int> mn(n, INT_MAX);
    mn[0] = arr[0];
    for (int i = 1; i < n; i++)
        mn[i] = min(arr[i], mn[i - 1]);
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= mn[i])
            s.pop();
        if (!s.empty() && s.top() < arr[i])
            return true;
        s.push(arr[i]);
    }
    return false;
}

// this is another approach for this problem, here we are not using mn vector
// instead we have a s3 variable, which is obviously kth value, we will push the element if it is smaller than arr[i]
// and instead of comparing with mn vector, here we are using the vector itself
bool find132pattern(vector<int> &arr)
{
    int s3 = INT_MIN;
    int n = arr.size();
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s3 > arr[i])
            return true;
        while (!s.empty() && s.top() < arr[i])
            s3 = s.top(), s.pop();
        s.push(arr[i]);
    }
    return false;
}
int main()
{
}