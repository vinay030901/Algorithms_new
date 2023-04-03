#include <bits/stdc++.h>
using namespace std;
int main()
{
    // set the ith bit of a numner
    // to do this we need to analyse something
    //                        3 2 1  0
    // for ex we have 1 1 0 0 0 1 1 0- and we need to set 2nd bit,
    // then we can create a mask, that is we can do OR operation of it with
    // 0100, so if 1 is present, then answer will be 1, otherwise it will be converted to 1

    int x = 120, n = 30;
    int mask = (1 << n); // means 2 power n
    x = mask | x;
    cout << x;
}