#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,l=1;
    cin>>t;
    while(t--)
    {
        int n,k,b,t;
        cin>>n>>k>>b>>t;
        vector<int>x(n),v(n);
        for(int i=0;i<n;i++)
            cin>>x[i];
        for(int i=0;i<n;i++)
            cin>>v[i];
        int swaps=0,count=0,not_possible=0;
        for(int i=n-1;i>=0;i--)
        {
            int dis=b-x[i];
            if(t*v[i]>=dis)
            {
                count++;
                if(not_possible>0)
                swaps+=not_possible;
            }
            else
            {
                not_possible++;
            }
            if(count>=k)
            break;
        }
        cout<<"Case #"<<l<<": ";
        if(count>=k)
        cout<<swaps<<endl;
        else
        cout<<"IMPOSSIBLE"<<endl;
        l++;
    }
}