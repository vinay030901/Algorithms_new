#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int l,int r,int x)
{
    while(l<=r){
    int mid=l+(r-l)/2;
    if(arr[mid]==x)
        return mid;
    if(arr[mid]<x)
        l=mid+1;
    else
        r=mid-1;}
    return -1;
}
int exponentialSearch(int arr[],int x,int n)
{
    int i=0;
    if(arr[i]==x)
    return i;
    else
    i++;
    while(arr[i]<x)
    {
        i=i*2;
        if(i>n)
        return -1;
    }
    return binarySearch(arr,i/2,i,x);
}
int main()
{
    int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21,
                34, 55, 89, 144, 233, 377, 610 };
    int x = 55;
    int n = sizeof(arr) / sizeof(arr[0]);
     
    // Find the index of 'x' using exponential Search
    int index = exponentialSearch(arr, x, n);
 
    // Print the index where 'x' is located
    cout << "\nNumber " << x << " is at index " << index;
    return 0;
}