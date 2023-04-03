/*count the inversion in an array
two elements a[i] and a[j] form an inversion if a[i]>a[j] and i<j

one approach might be the brute force approach where we can traverse the whole array and check the elements of size less that it
on the right side of the array, but it will take O(n^2) time

our approach is using merge sort, we count the inversions, time complexity is O(NlogN)*/

#include<bits/stdc++.h>
using namespace std;
int merge(int arr[],int temp[],int left,int mid,int right)
{
    int i=left,j=mid,k=left;
    int inv=0;
    while(i<=mid && j<=right)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];
            inv+=(mid-i+1);
        }
    }
    while(i<=mid)
    {
        temp[k++]=arr[i++];
    }
    while(j<=right)
    {
        temp[k++]=arr[j++];
    }
    for(int l=left; l<=right; l++)
        arr[l]=temp[l-left];
    return inv;
}
int mergeSort(int arr[],int temp[], int left, int right)
{
    int inv=0;
    if(left<right)
    {
        int mid=(left+right)/2;
        inv+=mergeSort(arr,temp,left,mid);
        inv+=mergeSort(arr,temp,mid+1,right);
        inv+=merge(arr,temp,left,mid,right);
    }
    return inv;
}
int main()
{
    int arr1[]={5,3,2,4,1};
    int arr[]={1,2,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    int temp[n];
    int inv=mergeSort(arr,temp,0,n-1);
    cout<<inv;
}