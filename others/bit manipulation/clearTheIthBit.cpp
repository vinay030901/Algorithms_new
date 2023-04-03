#include <bits/stdc++.h>
using namespace std;
int main()
{
    // to clear the ith bit, we can follow the same masking approach
    // here if we have 11000100 and we need to set the 2nd bit, then we need to and operation of that position with 0
    // but we need to do something, so that other position doesn't get affected
    // for this, we need 1 on other places
    // so we can make a typical 00000100 and then we can negate it and we will get 11111011
    int n = 13, i = 2;
    int mask = 1 << i;
    mask = ~(mask);
    n = n & mask;
    cout << n;
}