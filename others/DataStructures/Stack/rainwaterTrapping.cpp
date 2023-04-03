#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<int>left(n),right(n);
    int lmax=INT_MIN,rmax=INT_MIN;
    for(int i=0,j=n-1;i<n;i++,j--)
    {
        left[i]=max(lmax,v[i]);
        lmax=left[i];
        right[j]=max(rmax,v[j]);
        rmax=right[j];
    }
    int ar=0;
    for(int i=1;i<n-1;i++)
    {
        int m=min(left[i],right[i]);
        if(v[i]<m)
        {
            ar+=(m-v[i]);
        }
    }
    cout<<ar;
}