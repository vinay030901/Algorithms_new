#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stderr);
    freopen("outputf.out", "w", stdout);
#endif
    int t;
    cin>>t;
    set<string>menu;
    map<string,int>mpl,mpd;
    while(t--)
    {
        int l,d;
        cin>>l;
        for(int i=0;i<l;i++) 
        {
            string a;
            cin>>a;
            menu.insert(a);
            mpl[a]++;
        }
        cin>>d;
        for(int i=0;i<d;i++)
        {
            string a;
            cin>>a;
            menu.insert(a);
            mpl[a]--;
        }
    }
    int p=0;
    vector<string>ans;
    for(auto i=mpl.begin();i!=mpl.end();i++)
    {
        if(i->second>1)
        {
            p++;
            ans.push_back(i->first);}
    }
    cout<<p<<" ";
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
}