/*best time to buy and sell stock 
we have an array where ith elements is price of stock, we need to buy and sell one, design an algo for max profit*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int maxprofit = 0,min=INT_MAX;
    int arr[]={7,1,5,3,6,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
    {
        if(arr[i]<min)
            min=arr[i];
        maxprofit=max(arr[i]-min,maxprofit);
    }
    cout<<maxprofit<<endl;
}