#include<bits/stdc++.h>
using namespace std;
void insertionSort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(arr[j]>key && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
} 
void heapify(int arr[],int n,int i)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr[l]>arr[largest])
        largest=l;
    if(r<n && arr[r]>arr[largest])
        largest=r;
    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
void heapSort(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);
    for(int i=n-1;i>0;i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<"  ";
    cout<<"\n";
}

int main()
{
    int arr[]={6, 5, 3, 2, 8, 10, 9},k=3;
    int n=sizeof(arr)/sizeof(arr[0]);
    //we can solve this question in O(nk) time using insertion sort
    //insertionSort(arr,n);
    //printArray(arr,n);

    // but for solving it in O(n logK) time, we need to use heap
    heapSort(arr,n);
    printArray(arr,n);
}