/*You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.


Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105*/
#include <bits/stdc++.h>
using namespace std;
bool canJump(vector<int> &arr)
{
    int maxreach = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (maxreach < i)
            return false;
        maxreach = max(maxreach, i + arr[i]);
    }
    return true;
}
bool canJump(vector<int> &arr)
{
    int n = arr.size(), maxreach = arr[0], steps = arr[0], jumps = 0;
    if (n == 1)
        return true;
    if (arr[0] == 0)
        return false;
    for (int i = 1; i < n; i++)
    {
        maxreach = max(maxreach, arr[i] + i);
        if (i == n - 1)
            return true;
        steps--;
        if (steps == 0)
        {
            if (maxreach <= i)
                return false;
            jumps++;
            steps = maxreach - i;
        }
    }
    return true;
}
int main()
{
}