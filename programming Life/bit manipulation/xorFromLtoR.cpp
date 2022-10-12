#include <bits/stdc++.h>
using namespace std;
int computeXOR(int n)
{
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    else
        return 0;
}
int main()
{
    // we need to solve xor from l to r
    // if l=3 and r=6, then we need 3^4^5^6
    // important aspect is that we can find xor from 1 to 6 in constant time
    // so we have 1^2^3^4^5^6, to find 3^..6, we need to
    // xor (1^..6) with (1^2) so that 1 and 2 will cut
    // therefore xor is xor(r)^xor(l-1)
    int l = 3, r = 6;
    cout << (computeXOR(r) ^ computeXOR(l - 1)) << endl;
}