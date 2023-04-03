#include<bits/stdc++.h>
using namespace std;
long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(),a.end());
        long long mn=INT_MAX;
        for(int i=0;i<=n-m;i++)
        {
            if(mn>(a[i+m-1]-a[i]))
            mn=(a[i+m-1]-a[i]);
        }
        return mn;
    
    } 
int main()
{
    vector<long long>a= {7, 3, 2, 4, 9, 12, 56};
    long long n=a.size(),m=5;
    cout<<findMinDiff(a,n,m);
}