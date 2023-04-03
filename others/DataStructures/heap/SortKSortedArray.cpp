#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={6,5,3,2,8,10,9};
    int n=sizeof(arr)/sizeof(arr[0]),m=3,k=0;
    int newarr[n];
    priority_queue<int,vector<int>,greater<int>>minh;
    for(int i=0;i<n;i++)
    {
        minh.push(arr[i]);
        if(minh.size()>m)
            {
                newarr[k]=minh.top();
                minh.pop();
                k++;
            }
    }
    while(minh.size()>0)
    {
        newarr[k]=minh.top();
        minh.pop();
        k++;
    }
    cout<<"the sorted array is: ";
    for(int i=0;i<n;i++)
        cout<<newarr[i]<<" ";
}