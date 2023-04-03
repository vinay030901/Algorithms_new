//find pow(x,n)
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x=2,n=10;
    long long ans=1;
    while(n!=0)
    {
        if(n%2==0)
        {
            x=x*x;
            n/=2;
        }
        else
        {
            ans=ans*x;
            n-=1;
        }
    }
    if(n<0)
    ans=float(1/ans);
    cout<<"ans: "<<ans<<endl;
}