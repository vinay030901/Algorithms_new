#include<bits/stdc++.h>
using namespace std;
bool subset_sum(int arr[], int n,int sum) {
    bool t[n+1][sum+1];
    for(int j=0;j<=sum;j++)
        t[0][j]=false;
    for(int i=0;i<=n; i++)
        t[i][0]=true;
    for(int i=1;i<n+1;i++)
    for(int j=1;j<=sum;j++)
    {
        if(arr[i-1]<=j)
            t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
        else
            t[i][j]=t[i-1][j];
    }
    for(int i=0;i<=n; i++)
    {for(int j=0;j<=sum; j++)
        cout<<t[i][j];
        cout<<endl;}
    cout<<t[n+1][sum+1];
    return t[n+1][sum+1];
}
int main()
{
    int sum=11;
    int arr[]={2,3,7,8,10};
    int n=5;
    cout<<subset_sum(arr,n,sum);
}