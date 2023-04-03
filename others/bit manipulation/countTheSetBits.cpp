#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 15, cnt = 0;
    while (n)
    {
        n = n & (n - 1); // turning off the rightmost bit
        cnt++;
    }
    cout << cnt;
}