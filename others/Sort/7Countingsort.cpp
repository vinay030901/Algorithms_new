#include<bits/stdc++.h>
using namespace std;
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void countingSort(int arr[],int n)
{
    auto s =max_element(arr,arr+n);
    int size=*s,out[n];
    size++;
    cout<<"value of size is: "<<size<<endl;
    int count[size]={},k=0;
    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
    }
    cout<<"count array is: ";
    printArray(count,size);
    for(int i=1;i<size;i++)
        count[i]+=count[i-1];
    cout<<"count array is: ";
    printArray(count,size);
    for(int j=n-1;j>=0;j--)
    {
        --count[arr[j]];
        out[count[j]]=arr[j];
    }
    cout<<"ans array is: ";
    printArray(out,n);
}
int main()
{
    int arr[]={1, 4, 1, 2, 7, 5, 2};
    int n=sizeof(arr)/sizeof(arr[0]);
    countingSort(arr,n);
    printArray(arr,n);
}