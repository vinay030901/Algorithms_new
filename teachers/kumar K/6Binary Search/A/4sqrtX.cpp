/*
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.


Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.*/
#include <bits/stdc++.h>
using namespace std;
int mySqrt(int x)
{
    long long n = (long long)x;
    long long low = 0, high = n, mid;
    if (x == 1 || x == 0)
        return x;
    while (high - low > 1)
    {
        mid = (high + low) / 2;
        if (mid * mid == n)
            return mid;
        if (mid * mid < n)
            low = mid;
        else
            high = mid;
    }
    return (int)low;
}
int main()
{

    return 0;
}