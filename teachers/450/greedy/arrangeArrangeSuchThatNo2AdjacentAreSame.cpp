#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    int n=str.length();
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        if(mp.find(str[i])==mp.end())
        mp[str[i]]=1;
        else
        mp[str[i]]++;
    }
    priority_queue<pair<int, int>>mx;
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        mx.push({it->second,it->first});
    }
    int a=mx.top().first;
    cout<<a<<" "<<endl;
    if((n%2==0 && a>=n/2+1) || a>=n/2+2)
    {
        cout<<"not possible";
        return 0;
    }
    string str1=""; 
    while(!mx.empty())
    {
        int tf=mx.top().first,ts=mx.top().second;
        str1+=ts;
        mx.pop();
        if(mx.empty())
        break;
        int df=mx.top().first,ds=mx.top().second;
        str1+=ds;
        mx.pop();
        tf-=1;
        if(tf>0)
        mx.push({tf,ts});
        df-=1;
        if(df>0)
        mx.push({df,ds});
    }
    cout<<str1;
}