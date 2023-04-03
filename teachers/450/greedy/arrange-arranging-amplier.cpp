#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,ones=0;
        cin>>n;
        vector<ll>v(n);
        for(ll i=0;i<n;i++)
            {cin>>v[i];
            if(v[i]==1)
            ones++;}
        sort(v.begin(),v.end(),greater<ll>());
        for(ll i=0;i<ones;i++)
        cout<<1<<" ";
        if((n-ones)==2 && v[0]==3 && v[1]==2)
            cout<<"2 3";
        else
        {
            for(ll i=0;i<(n-ones);i++)
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}

