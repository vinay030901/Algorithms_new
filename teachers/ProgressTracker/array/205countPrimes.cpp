/*Given an integer n, return the number of prime numbers that are strictly less than n.
Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0


Constraints:

0 <= n <= 5 * 106*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countPrimes(int n)
    {
        if (n == 0)
            return 0;
        bool prime[n];
        memset(prime, true, sizeof(prime));
        for (int p = 2; p < sqrt(n); p++)
        {
            if (prime[p] == true)
            {
                for (int i = p * p; i < n; i += p)
                    prime[i] = false;
            }
        }
        int ans = 0;
        for (int i = 2; i < n; i++)
            if (prime[i] == true)
                ans++;
        return ans;
    }
};
int main()
{
    // Your code here
    return 0;
}