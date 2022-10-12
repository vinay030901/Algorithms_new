#include<bits/stdc++.h>
using namespace std;
int celebrity(int n,vector<vector<int> >v )
    {
        stack<int>s;
        for(int i=0;i<n;i++)
        s.push(i);
        while(s.size()>1)
        {
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            if(v[a][b]==1)
            s.push(b);
            else if(v[b][a]==1)
            s.push(a);
        }
        if(s.empty()) return -1;
        int p=s.top();
        for(int i=0;i<n;i++)
        {
            if(v[p][i]==1) return -1;
            if(i!=p && v[i][p]==0) return -1;
            
        }
        return p;
    }
int main()
{
    int n;
    n=3;
    vector<vector<int>>v{{0,1,0},
         {0,0,0}, 
         {0,1,0}};
    cout<<celebrity(n,v);
}