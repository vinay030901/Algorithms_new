#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x = 39;
    // no of leading zeros
    cout << __builtin_clz(x) << endl;

    // no of trailing zeros
    cout << __builtin_ctz(x) << endl;

    // no of set bits
    cout << __builtin_popcount(x) << endl;
}