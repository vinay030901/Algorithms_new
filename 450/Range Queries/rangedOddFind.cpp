#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, q;
        cin >> n >> q;
        vector<ll> v(n), odd(n+1);
        unordered_map<ll, ll> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<vector<ll>> query(q);
        for (int i = 0; i < q; i++)
        {
            ll a, b, c;
            cin >> a >> b >> c;
            query[i].push_back(a);
            query[i].push_back(b);
            query[i].push_back(c);
        }

        cout << "vector made is: ";
        odd[0] = 0;
        cout<<odd[0]<<" ";
        for (int i = 1; i < n+1; i++)
        {
            if (mp.find(v[i-1]) == mp.end())
            {
                odd[i] = odd[i - 1] + 1;
                mp[v[i-1]] = 1;
            }
            else
            { 
                ++mp[v[i-1]];
                if (mp[v[i-1]] % 2 == 0)
                    odd[i] = odd[i - 1] - 1;
                else
                    odd[i] = odd[i - 1];
            }
            cout << odd[i] << " ";
        }
        for(int i=0; i<q; i++)
        {
            if(query[i][0] ==1)
            {
                int ind=query[i][1]-1,val=query[i][2];
                
            }
        }
    }
}