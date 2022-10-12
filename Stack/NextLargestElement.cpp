#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(2*n),ans;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        v[n+i]=v[i];}

    stack<int>s;
    ans.push_back(-1);
    n=v.size();
    s.push(v[n-1]);
    for(int i=n-2;i>=0;i--)
    {
        bool f=false;
        while(v[i]>=s.top())
        {
            s.pop();
            if(s.empty())
            {ans.push_back(-1);
            f=true; 
            s.push(v[i]);
            break;}

        }
        if(f==false){
        ans.push_back(s.top());
        s.push(v[i]);}
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<"  ";
}