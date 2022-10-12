#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x,y;
        cin>>n>>x>>y;
        if(x==y)
        cout<<"0\n";
        else if((x%2==0 && y%2==0)||(x%2==1 && y%2==1))
        cout<<"0\n";
        else
        cout<<"1\n";
    }
}