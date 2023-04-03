/*given an array nums, we call (i,j) an important revese pair if i<j and nums[i]>2*nums[j]. you need to return the number of pairs
approach 1 could just be to traverse the array and check for such elements and count them but it will take O(n^2) time.
we can do it in O(NlogN) time using merge sort as done in inverse pair solution*/
#include<bits/stdc++.h>
using namespace std;
int merge(int arr[],int low,int mid,int high)
{
    int cnt=0;
    int j=mid+1;
    for(int i=low;i<=mid;i++){
        while(arr[i]>2LL*arr[j] && j<=high)
            j++;
        cnt+=(j-(mid+1));
    }
    int i=low;
    j=mid+1;
    vector<int>temp;
    while(i<=mid && j<=high) {
        if(arr[low]<=arr[high]) {
            temp.push_back(arr[i++]);
        }
        else
            temp.push_back(arr[j++]);
    }
    while(i<=low)
        temp.push_back(arr[i++]);
    while(j<=high)
        temp.push_back(arr[j++]);
    for(int i=low;i<=high;i++)
        arr[i]=temp[i-low];
    return cnt;
}
int mergeSort(int arr[],int low,int high)
{
    if(low>=high) return 0;
    int mid=(low+high)/2;
    int cnt=mergeSort(arr,low,mid);
    cnt+=mergeSort(arr,mid+1,high);
    cnt+=merge(arr,low,mid,high);
    return cnt;
}
int main()
{
    int arr[]={-5,-5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<mergeSort(arr,0,n-1);
}