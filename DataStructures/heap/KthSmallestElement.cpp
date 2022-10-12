#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={7,10,9,8,20,15};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    priority_queue<int> maxheap;
    for(int i=0;i<n;i++)
    {
        maxheap.push(arr[i]);
        if(maxheap.size()>k)
            maxheap.pop();
    }
    cout<<"the kth largest element is: "<<maxheap.top();
}