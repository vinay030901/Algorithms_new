#include<bits/stdc++.h>
using namespace std;
bool subsetSum(int arr[],int sum,int n)
    {
        int t[n+1][sum+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(i==0)
                    t[i][j]=false;
                else if(j==0)
                    t[i][j]=true;
                else if(arr[i-1]<=j)
                {
                    t[i][j]=t[i-1][j-arr[i-1]]||t[i-1][j];
                }
                else
                    t[i][j]=t[i-1][j];
            }
        }
        cout<<"value of t[n][sum] = "<<t[n][sum]<<endl;
        return t[n][sum];
    }
    bool findPartition(int arr[], int n)
    {
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=arr[i];
        if(sum%2!=0)
            return false;
        else 
        return subsetSum(arr,sum/2,n);
    }
int main()
{
    int arr[]={5,11,5,1};
    int n =4;
    bool t=findPartition(arr,n);
    cout<<t;
}