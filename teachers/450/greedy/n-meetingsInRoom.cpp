#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>>v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(),[&](vector<int>&a,vector<int>&b){
        return a[1]>b[1];
    });
    int end=v[0][1],mx,start;
    for(int i=1;i<=n;i++)
    {
        start=v[i][1];
        if(start>=end)
        mx++;
    }
    cout<<mx;
}