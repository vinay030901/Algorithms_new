#include <bits/stdc++.h>
using namespace std;
int main()
{
    // we need to remove the last set here
    // so we have 1010, then we need 1000
    // we need to do AND operation with n-1
    // since we know that if we would have added 1 to n-1
    // then adding to any 1 would have shifted
    // so logic here is simple

    int n = 52376;
    cout << (n & (n - 1));

    // we have 12(which 8+4), now 1 is decrease and then 4 will be
    // broken ti (2+1), so 1 at 0th bit and 1st will be removed
    // therefore and operation will remove the first set bit
}