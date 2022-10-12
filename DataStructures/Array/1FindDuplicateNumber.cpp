/* find the duplicate number in range n+1*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr1[]={2,5,6,9,3,8,9,7,1};
    int arr[]={2,5,9,5,3,8,6,7,1,4};
    int n=sizeof(arr) / sizeof(arr[0]);
    //hashing approach
    /*int map[n+1]={0};
    for(int i=0;i<n+1;i++)
    {
        map[arr[i]]++;
    }
    for(int i=0;i<n+1;i++)
    {
        if(map[i]>1)
            cout<<i<<endl;
    }*/
    /*we can use the hashing approach but it will take O(n) space, so instead of it, we will go for cyclic linkedlist approach
    we are going to use tortoise and hare algorithm, in which we will traverse with two pointers, and speed of them would be 2 and 1,
    the position at which both will meet will be the repeating number*/
    int fast=arr[0];
    int slow=arr[0];
    do{
        slow=arr[slow];
        fast=arr[arr[fast]];
    }while(slow!=fast);
    fast=arr[0];
    while(slow!=fast)
    {
        fast=arr[fast];
        slow=arr[slow];
    }
    cout<<slow<<endl;
}