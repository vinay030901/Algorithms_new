#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=7;
    int arr[]={20,27,15,6,19,24,72};
    priority_queue<int,vector<int>,greater<int>>minh;
    for(int i=0;i<n;i++) 
        minh.push(arr[i]);
    while(minh.size()!=0){
        cout<<minh.top()<<" ";
        minh.pop();
    }
}