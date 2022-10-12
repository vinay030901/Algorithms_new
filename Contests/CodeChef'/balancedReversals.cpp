#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string str;
        cin>>str;
        ll cnt1=0,cnt0=0;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='1') cnt1++;
            else cnt0++;
        }
        string ans="";
        for(int i=0;i<cnt0;i++)
        ans+='0';
        for(int i=0;i<cnt1;i++)
        ans+='1';
        cout<<ans<<endl;
    }
}