#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
bool check(int n)
{
    while (n)
    {
        if (n % 10 == 4)
            return false;
        n /= 10;
    }
    return true;
}
int findNumber(int l, int r)
{
    int ans = 0;
    for (int i = l; i <= r; i++)
    {
        if (i % 4 == 0)
            continue;
        if (check(i))
        {
            ans++;
        }
            
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        cout << findNumber(l, r) << "\n";
    }
}