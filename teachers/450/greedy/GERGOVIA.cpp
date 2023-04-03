#include<bits/stdc++.h>
using namespace std;
void solve()
{
        int n;
        cin>>n;
        int v[n];
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        vector<pair<int,int>>buy,sell;
        for(int i=0;i<n;i++){
            if(v[i]>0)
                buy.push_back({v[i],i});
            else
                sell.push_back({v[i],i});
        }
        int i=0,j=0,ans=0;
        while(i<buy.size() && j<sell.size())
        {
            int x=min(buy[i].first,-sell[j].first);
            buy[i].first-=x;
            sell[j].first+=x;
            int diff=abs(buy[i].second-sell[j].second);
            ans+=(x*diff);
            if(buy[i].first==0) i++;
            if(sell[j].first==0) j++;
        }   
        cout<<ans<<"\n";
}
int32_t main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      solve();
      return 0;  
}