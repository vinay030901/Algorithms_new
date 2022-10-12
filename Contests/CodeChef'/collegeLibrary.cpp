#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>v(n-1);
        for(int i=0;i<n-1;i++)
        cin>>v[i];
        long long sum=accumulate(v.begin(),v.end(),0);
        long long total=(n*(n+1))/2;
        cout<<total-sum<<endl;
    }
}    