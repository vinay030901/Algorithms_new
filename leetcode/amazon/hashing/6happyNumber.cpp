/*
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.



Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Example 2:

Input: n = 2
Output: false
*/
#include <bits/stdc++.h>
using namespace std;
int digitSquareSum(int n)
{
    int sum = 0, tmp;
    while (n)
    {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n)
{
    int slow, fast;
    slow = fast = n;
    do
    {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
        if (fast == 1)
            return 1;
    } while (slow != fast);
    return 0;
}
// using hashing
bool isHappy(int n)
{
    int num = n;
    unordered_map<int, int> mp;
    while (num != 1)
    {
        string str = to_string(num);
        int val = 0;
        for (int i = 0; i < str.size(); i++)
        {
            val += ((str[i] - '0') * (str[i] - '0'));
        }
        if (val == 1)
            return true;
        num = val;
        if (++mp[val] == 2)
            return false;
    }
    return true;
}