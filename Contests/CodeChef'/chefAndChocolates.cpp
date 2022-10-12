#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int c,x,y;
        cin>>c>>x>>y;
        int have=c-x;
        cout<<y*have<<endl;
    }
}