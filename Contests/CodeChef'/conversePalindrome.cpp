#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll  t;
    map<char,char>mp={{'a','z'},{'b','y'},{'c','x'},{'d','w'},{'e','v'},{'f','u'},{'g','t'},{'h','s'},{'i','r'},{'j','q'},{'k','p'},{'l','o'},{'m','n'},
    {'n','m'},{'o','l'},{'p','k'},{'q','j'},{'r','i'},{'s','h'},{'t','g'},{'u','f'},{'v','e'},{'w','d'},{'x','c'},{'y','b'},{'z','a'}};
    cin>>t;
    while(t--)
    {
        ll n;
        int f=0;
        cin>>n;
        string str;
        cin>>str;
        for(ll i=0,j=n-1;i<n/2;i++,j--)
        {
            if(mp[str[i]]!=str[j])
            {
                f=1;
                break;
            }
        }
        if(f==0) cout<<"YES\n";
        else if(f==1) cout<<"NO\n";
    }
}
