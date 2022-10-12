#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,d,f=0;
    cin>>n>>d;
    string ans="";
    if(n<0 && d<0) f=0;
    else if(n<0) f=1;
    else if(d<0) f=1;
    if(f==1)
    {
        ans+="-";
        if(n<0) n=n*(-1);
        else if(d<0) d=d*(-1);
    }
    int q=n/d;
    ans+=to_string(q);
    int rem=n%d;
    if(rem==0)
    {
        cout<<ans<<endl;
        exit(0);
    }
    ans=ans+".";
    unordered_map<int,int>mp;
    while(rem!=0){
    if(mp.find(rem)==mp.end())
    {
        mp[rem]=ans.length();
        n=rem*10;
        q=n/d;
        ans=ans+to_string(q);
        rem=n%d;
    }
    else{
        ans.insert(mp[rem],"(");
        ans.append(")");
        cout<<ans<<endl;
        exit(0);
    }
    }
    cout<<ans<<endl;
}