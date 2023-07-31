#include <bits/stdc++.h>
using namespace std;
int reverse(int x)
{
    int upper = pow(2, 31) / 10;
    int lower = -pow(2, 31) / 10;
    int ans = 0;
    while (x)
    {
        int rem = x % 10;
        if (ans >= lower && ans <= upper)
        {
            ans = ans * 10 + rem;
            x /= 10;
        }
        else
            return 0;
    }
    return ans;
}
int main()
{
}