#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n,m;
    cin>>n>>m;
    int k=n-m;
    m=max(k,m);
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end(),greater<int>());
    int sum=0,sum2=0;
    for(int i=0;i<m;i++) sum+=v[i];
    for(int i=m;i<n;i++) sum2+=v[i];
    cout<<sum-sum2<<endl;
}
int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        solve();
    }
}