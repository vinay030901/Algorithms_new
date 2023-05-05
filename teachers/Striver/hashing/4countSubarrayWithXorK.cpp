/*we solved this question by taking into account the equation that A^B=K then B=A^K
so by continuously traversing the array and finding the xor, we will get A, and we will xor it with k
to find the whether we have encountered B at sometime*/
/*
Given an array of integers A and an integer B.
Find the total number of subarrays having bitwise XOR of all elements equals to B.
Problem Constraints
1 <= length of the array <= 105
1 <= A[i], B <= 109
Input Format
The first argument given is the integer array A.
The second argument given is integer B.
Output Format
Return the total number of subarrays having bitwise XOR equals to B.
Example Input
Input 1:
 A = [4, 2, 2, 6, 4]
 B = 6
Input 2:
 A = [5, 6, 7, 8, 9]
 B = 5
Example Output
Output 1:
 4
Output 2:
2
Example Explanation
Explanation 1:
 The subarrays having XOR of their elements as 6 are:
 [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]
Explanation 2:
 The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]  */
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &A, int B)
{
    unordered_map<int, int> mp;
    int _xor = 0, cnt = 0;
    mp[_xor] = 1;
    for (auto it : A)
    {
        _xor ^= it;
        if (mp.find(_xor ^ B) != mp.end())
            cnt += mp[_xor ^ B];
        mp[_xor]++;
    }
    return cnt;
}