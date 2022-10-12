#include<iostream>
using namespace std;
void insertionSort(int arr[],int n)
{
    int key,i,j;
    for(i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(arr[j]>key && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
void printArray(int a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
int main()
{
    int arr[] = {64, 25, 12, 22, 11}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    insertionSort(arr, n); 
    cout << "Sorted array: \n"; 
    printArray(arr, n); 
    return 0; 
}