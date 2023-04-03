#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={5,6,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x=7,k=3;
    priority_queue<pair<int,int>>maxh;
    for(int i=0;i<n;i++)
    {
        /*pair<int,int>p1;
        p1.first=abs(arr[i]-x);
        p1.second=arr[i];
        maxh.push(p1);*/
        maxh.push({abs(arr[i]-x),arr[i]});
        if(maxh.size()>k)
            maxh.pop();
    }
    cout<<"the k-nearest elements are- ";
    for(int i=0;i<k;i++)
    {
        cout<<maxh.top().second<<" ";
        maxh.pop();
    }
}