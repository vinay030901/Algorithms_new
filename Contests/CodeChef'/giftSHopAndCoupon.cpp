#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll>v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        ll cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (k >= v[i]) {
                k -= v[i];
                cnt++;
            }
            else
            {
                if (k >= ceil(v[i] / 2.0))
                {
                    k -= ceil(v[i] / 2.0);
                    cnt++;
                }
                else break;
            }
        }
        cout << cnt << endl;
    }
}