#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={-2,-3,4,-1,-2,5,-3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=0,maxi=arr[0];
    for(int i=0;i<n;i++)
    {
        if(sum>=0)
            sum=sum+arr[i];
        else
            sum=arr[i];
        if(sum>maxi)
            maxi=sum;  
    }
    cout<<"maximum sum subarray is: "<<maxi<<endl;
}