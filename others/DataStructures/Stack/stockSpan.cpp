#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    /*stack<pair<int, int>>s;
    vector<int>ans;
    s.push({v[0],1});
    ans.push_back(1);
    for(int i=1;i<n;i++)
    {
        int cnt=1;
        while(v[i]>=s.top().first && (!s.empty()))
        {
            cnt+=s.top().second;
            s.pop();
        }
        s.push({v[i],cnt});
        ans.push_back(cnt);
    }
    for(int i=0;i<n;i++)
    cout<<ans[i]<<" ";*/
    stack<int>s;
    vector<int>ans;
    ans.push_back(1);
    s.push(0);
    for(int i=1;i<n;i++)
    {
        if(s.size()==0)
        ans.push_back(1);
        if(s.size()>0 && v[s.top()]<v[i])
        {
            while(s.size()>0 && v[s.top()]<v[i])
            s.pop();
        }
        if(s.size()==0)
        ans.push_back(i+1);
        else
        ans.push_back(i-s.top());
        s.push(i);
    }
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<"  ";
}