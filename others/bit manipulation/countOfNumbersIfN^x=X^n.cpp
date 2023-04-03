#include <bits/stdc++.h>
using namespace std;
int count(int n)
{
    int unset_bits = 0;
    while (n)
    {
        if ((n & 1) == 0)
            unset_bits++;
        n = n >> 1;
    }
    return unset_bits;
}
int main()
{
    // Count of numbers (x) smaller than or equal to n such that n+x = n^x:
    // The count of such numbers x can be counted using the following mathematical trick.

    // The count = pow(2, count of zero bits).
    /*
    An efficient solution is as follows

    we know that (n+i)=(n^i)+2*(n&i)
    So n + i = n ^ i implies n & i = 0
    Hence our problem reduces to finding values of i such that n & i = 0. How to find count of such pairs? We can use the count of unset-bits in the binary representation of n. For n & i to be zero, i must unset all set-bits of n. If the kth bit is set at a particular in n, kth bit in i must be 0 always, else kth bit of i can be 0 or 1
    Hence, total such combinations are 2^(count of unset bits in n)
    For example, consider n = 12 (Binary representation : 1 1 0 0).
    All possible values of i that can unset all bits of n are 0 0 0/1 0/1 where 0/1 implies either 0 or 1. Number of such values of i are 2^2 = 4.

The following is the program following the above idea.  */
}