#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[30]={3,4,1,2,6,5,78,65};
    int n=sizeof(arr)/sizeof(arr[0]);
    make_heap(arr,arr+n);//making a heap with the help of an array
    priority_queue<int> maxheap;// to make a max heap
    priority_queue<int,vector<int>,greater<int>> minheap;//declaring a min heap

    //to insert a new element in heap
    arr[8]=30;
    push_heap(arr,arr+(sizeof(arr)/sizeof(arr[0])));
    maxheap.push(30);

    //popping an element
    maxheap.pop();

    //sorting a heap
    sort_heap(arr,arr+(sizeof(arr)/sizeof(arr[0])));
    
}