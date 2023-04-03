#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={2,4,2,1,1,4,3,2,5,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
        mp[arr[i]]++;
    priority_queue<pair<int,int>>maxh;
    for(auto i=mp.begin();i!=mp.end();i++)
    {
        maxh.push({i->second,i->first});
    }
    int i=0,k;
    while(maxh.size()>0){
        k=maxh.top().first;
        for(int j=0;j<k;j++){
        arr[i]=maxh.top().second;
        i++;}
        maxh.pop();
    }
    cout<<"the frequency sort is: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}