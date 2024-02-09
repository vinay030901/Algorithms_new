/*
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.


Constraints:

1 <= n <= 104*/
#include <bits/stdc++.h>
using namespace std;
int numSquares(int n)
{
    queue<int> q;
    q.push(0);
    unordered_set<int> vis;
    vis.insert(0);
    int step = 0;
    while (!q.empty())
    {
        int size = q.size();
        step++;
        while (size--)
        {
            int cur = q.front();
            q.pop();
            for (int i = 0; i * i <= n - cur; i++)
            {
                int var = cur + i * i;
                if (var == n)
                    return step;
                if (vis.find(var) == vis.end())
                {
                    vis.insert(var);
                    q.push(var);
                }
            }
        }
    }
    return step;
}
// https://leetcode.com/problems/perfect-squares/discuss/71488/Summary-of-4-different-solutions-(BFS-DP-static-DP-and-mathematics)
// ALSO TECHDOSE
bool issquare(int n)
{
    return ceil(sqrt(n)) == floor(sqrt(n));
}
int numSquares(int n)
{
    // if number is in the form of 4^a(8*b+7)
    if (issquare(n))
        return 1;
    while (n % 4 == 0)
        n /= 4;
    if (n % 8 == 7)
        return 4;
    // check whether 2 is the result
    int sqrt_n = (int)sqrt(n);
    for (int i = 1; i <= sqrt_n; i++)
    {
        if (issquare(n - i * i))
            return 2;
    }
    return 3;
}
int main()
{
    // Your code here
    return 0;
}