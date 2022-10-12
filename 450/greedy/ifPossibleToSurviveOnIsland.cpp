#include<bits/stdc++.h>
using namespace std;
int main()
{
    int s,m,n,cnt=0;
    cin>>s>>m>>n;
    if(m>n || ((m*7>n*6) && (s>6)))
        cout<<"No";
    else
    {
        int b=n/m;
        int days=s/b+1;
        cout<<"Yes for "<<days<<" buys";
}}