#include<bits/stdc++.h>
using namespace std;
int main()
{
    pair<int,int>arr[]={{1,3},{-2,2},{5,8},{0,1}};
    int k=2,n=4;
    priority_queue<pair<int,pair<int,int>>>maxh;
    for(int i=0;i<n;i++)
    {
        maxh.push({pow(arr[i].first,2)+pow(arr[i].second,2),{arr[i].first,arr[i].second}});
        if(maxh.size()>k)
            maxh.pop();
    }
    cout<<"the closest elements to origin are- \n";
    while(maxh.size()>0)
    {
        cout<<maxh.top().second.first<<" "<<maxh.top().second.second<<"\n";
        maxh.pop();
    }
}