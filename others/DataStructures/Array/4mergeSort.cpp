/*merge two sorted arrays using O(1) space*/
#include<bits/stdc++.h>
using namespace std;
void insertionSort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main()
{
    int a1[]={1,4,7,8,10};
    int a2[]={2,3,9};
    int n=sizeof(a1)/sizeof(a1[0]);
    int n1=sizeof(a2)/sizeof(a2[0]);
    for(int i=0;i<n;i++)
    {
        if(a1[i]>a2[0])
        {
            swap(a1[i],a2[0]);
            insertionSort(a2,n1);
        }
    }
    cout<<"the sorted array is: ";
    for(int i=0;i<n;i++)
        cout<<a1[i]<<" ";
    for(int i=0;i<n1;i++)
        cout<<a2[i]<<" ";
    
}