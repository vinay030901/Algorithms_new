#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={1,1,1,3,2,2,4,6,7};
    int n=sizeof(arr)/sizeof(arr[0]),k=2;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    //printing the map
    /*cout<<"map is: \n";
    for(auto i=mp.begin();i!=mp.end();i++)
    {
        cout<<i->first<<"  "<<i->second<<"\n";
    }*/
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minh;
    for(auto i=mp.begin();i!=mp.end();i++)
    {
        minh.push({i->second,i->first});
        if(minh.size()>k)
            minh.pop();

    }
    for(int i=0;i<k;i++)
    {
        cout<<minh.top().second<<" ";
        minh.pop();
    }
}