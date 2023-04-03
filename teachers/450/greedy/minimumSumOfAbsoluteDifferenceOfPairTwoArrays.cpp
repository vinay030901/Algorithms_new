#include<bits/stdc++.h>
using namespace std;
void findMin(int arr[],int brr[],int n)
{
    sort(arr,arr+n);
    sort(brr,brr+n);
    int sum=0;
    for(int i=0;i<n;i++)
    sum+=abs(arr[i]-brr[i]);
    cout<<sum;
}
int main()
{
    int arr[]={4,1,8,7},brr[]={2,3,6,5};
    findMin(arr,brr,4);
}