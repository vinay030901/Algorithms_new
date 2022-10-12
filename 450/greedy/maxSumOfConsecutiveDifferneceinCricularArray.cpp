#include<bits/stdc++.h>
using namespace std;
int mininumAbsoluteDifference(int arr[],int n){
    sort(arr,arr+n);
    vector<int>v;
    for(int i=0,j=n-1;i<n/2;i++,j--)
    {
        v.push_back(arr[i]);
        v.push_back(arr[j]);
    }
    if(n%2!=0){
        v.push_back(arr[n/2]);
    }
    v.push_back(arr[0]);
    int sum=0;
    for(int i=0;i<v.size()-1;i++){
        sum+=abs(v[i]-v[i+1]);
    }
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    cout<<"\n";
    return sum;
}
int main()
{
    int arr[]={1,2,5,4,8};
    int ar[]={10,12,15};
    cout<<mininumAbsoluteDifference(ar,3);
}