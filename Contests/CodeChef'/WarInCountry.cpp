#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, x, y;
        cin >> n >> x >> y;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        ll time = 0;
        ll mx=*max_element(a.begin(), a.end());
        vector<ll>v(mx+1,0);
        for(ll j=0;j<n;j++){
            for(ll i=a[j];i<=mx;i+=a[j])
            v[i]+=y;
        }
        ll sum = 0;
        ll i=1;
        while (true)
        {
            time++;
            sum+=v[i];
            if(i>=mx) i=1;
            if (sum >= x)
                break;
            i++;
        }
        cout << time << endl;
    }
}