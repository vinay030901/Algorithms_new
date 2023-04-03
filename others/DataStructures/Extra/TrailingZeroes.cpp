#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,sum=0;
    cin>>n;
    /*for(int i=5;i<=n;i*=5)
    {
        cout<<sum<<"+="<<n<<" / "<<i<<endl;
        sum+=(n/i);
    }*/
    while(n>=5)
    {
        sum+=(n/5);
        n/=5;
    }
    cout<<sum;
}