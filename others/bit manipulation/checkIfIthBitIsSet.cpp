#include <bits/stdc++.h>
using namespace std;
int main()
{
    // to check if a nth bit is set or not
    // to do this we need to analyse something
    //                        3 2 1  0
    // for ex we have 1 1 0 0 0 1 1 0- and we need to check 2nd bit,
    // then we can create a mask, that is we can do AND operation of it with
    // 0100, so if 1 is present, then answer will be 1, otherwise 0

    int x = 120, n = 4;
    int mask = (1 << n); // means 2 power n
    if (mask & x)
        cout << "yes";
    else
        cout << "no";
}