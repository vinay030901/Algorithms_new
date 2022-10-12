#include<bits/stdc++.h>
using namespace std;
int partition(int arr[],int l,int h)
{
    int pivot=arr[h];
    int i=l-1;
    for(int j=l;j<h;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1;
}
void quickSort(int arr[], int l,int h)
{
    int stack[h-l+1];
    int top=-1;
    stack[++top]=l;
    stack[++top]=h;
    while(top>=0)
    {
        h=stack[top--];
        l=stack[top--];
        int p=partition(arr,l,h);
        if(p-1>l)
        {
            stack[++top]=l;
            stack[++top]=p-1;
        }
        if(p+1<h)
        {
            stack[++top]=p+1;
            stack[++top]=h;
        }
    }
}
void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
int main()
{
    int arr[]={6,5,2,5,7,9,0,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n-1);
    printArray(arr,n);
}