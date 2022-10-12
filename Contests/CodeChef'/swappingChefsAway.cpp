#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isSorted(string str,ll n)
{
    for(int i=0;i<n-1;i++)
    if(str[i]>str[i+1]) return false;
    return true;
}
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
        for(int i=0,j=n-1;i<n/2;i++,j--)
        {
            if(str[i]<str[j]) swap(str[i],str[j]);
        }
        if(isSorted(str,n)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}