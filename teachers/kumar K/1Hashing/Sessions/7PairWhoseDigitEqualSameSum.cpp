/*
Question1: Given an array A consisting of N integers, returns the maximum sum of two numbers whose digits add up to an equal sum.
if there are not two numbers whose digits have an equal sum, the function should return -1.
Constraints: N is integer within the range [1, 200000]
each element of array A is an integer within the range [1, 1000000000]
Example1:
Input:
A = [51, 71, 17, 42]
Output: 93
Explanation: There are two pairs of numbers whose digits add up to an equal sum: (51, 42) and (17, 71), The first pair sums up to 93
Example2:
Input:
A = [42, 33, 60]
Output: 102
Explanation: The digits of all numbers in A add up the same sum, and choosing to add 42 and 60 gives the result 102
Example3:
Input:
A = [51, 32, 43]
Output: -1
Explanation: All numbers in A have digits that add up to different, unique sums*/
#include <bits/stdc++.h>
using namespace std;
int digitSumFun(int n)
{
    int sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int fun(vector<int> &arr)
{
    unordered_map<int, vector<int>> mp;
    for (auto it : arr)
    {
        int digitSum = digitSumFun(it);
        if (mp.find(digitSum) == mp.end() || mp[digitSum].size() == 1)
        {
            mp[digitSum].push_back(it);
        }
        else
        {
            vector<int> v = mp[digitSum];
            if (it > v[0] && it > v[1])
                v[1] > v[0] ? mp[digitSum][0] = it : mp[digitSum][1] = it;
            else if (it > v[0])
                mp[digitSum][0] = it;
            else if (it > v[1])
                mp[digitSum][1] = it;
        }
    }
    int mx = -1;
    for (auto it : mp)
        if (it.second.size() > 1)
            mx = max(mx, it.second[0] + it.second[1]);
    return mx;
}
int main()
{
    vector<int> arr = {51, 32, 43};
    cout << fun(arr) << endl;
    return 0;
}