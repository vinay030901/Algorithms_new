#include <bits/stdc++.h>
using namespace std;
int findSmallest(int arr[],int n){
    sort(arr,arr+n);
    int sum=accumulate(arr,arr+n,0),rsum=0,leftsum,cnt=0;
    for(int i=0,j=n-1;i<=n/2;i++,j--){
        rsum+=arr[j];
        leftsum=sum-rsum;
        cnt++;
        if(rsum>leftsum)
            return cnt;
    }
    return cnt;
}
int main()
{
    int arr[]={1,1,1,1};
    cout<<findSmallest(arr,4);
}