#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={0,2,5,8,100,2,3,5,8,11,5,8,13,21,34,2,3,5,8,13};
    int n=sizeof(arr)/sizeof(arr[0]);
    int l=2;
    vector<int>mx={0,2,5,8,100,2,3,5,8,13,11,5,8,13,21,34,2,3,5,8,13};
    for(int i=2;i<n;i++)
    {
        vector<int>v;
        if(arr[i]==arr[i-1]+arr[i-2])
        {
            v.push_back(arr[i-2]);
            v.push_back(arr[i-1]);
            while(arr[i]==arr[i-1]+arr[i-2])
            {
                v.push_back(arr[i]);
                i++;
            }
            if(v.size()<mx.size())
            mx=v;
        }
    }
    cout<<"ans: ";
    for(int i=0;i<mx.size();i++){
        cout<<mx[i]<<" ";
    }
}