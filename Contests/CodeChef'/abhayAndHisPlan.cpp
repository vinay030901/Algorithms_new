#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    while (cin >> n) {
        vector<ll>v(n);
        for (ll i = 0; i < n; i++) cin >> v[i];
        ll sum1 = 0, sum2 = 0;
        for (ll i = 0; i < n; i += 2) sum1 += v[i];
        for (ll i = 1; i < n; i += 2) sum2 += v[i];
        if (sum1 > sum2) cout << sum1 << endl;
        else cout << sum2 << endl;
        return 0;
    }
}