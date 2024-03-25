/*An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.



Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.


Constraints:

1 <= n <= 1690*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        if (n < 7)
            return n;
        priority_queue<long long, vector<long long>, greater<long long>> mn;
        mn.push(1);
        long long top;
        while (n--)
        {
            top = mn.top();
            while (!mn.empty() && mn.top() == top)
                mn.pop();
            mn.push(top * 2);
            mn.push(top * 3);
            mn.push(top * 5);
        }
        return top;
    }
};
int main()
{
    // Your code here
    return 0;
}