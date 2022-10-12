#include<bits/stdc++.h>
using namespace std;
int mian()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)
        cin>>a[i];
        vector<int>b(32);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<32;j++)
            b[j]=((a[i]&(1<<j))>0);
        }
    int ans=0;
    for(int i=0;i<32;i++)
    {
        if(b[i]>=32)
        ans|=(1<<i);
    }
    cout<<ans<<endl;}
    
}