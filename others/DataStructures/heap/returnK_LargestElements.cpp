#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={7,10,4,3,15,20};
    int n=sizeof(arr)/(sizeof(arr[0])),k=3;
    priority_queue<int,vector<int>,greater<int>>minh;
    for(int i=0;i<n;i++)
        {
            minh.push(arr[i]);
            if(minh.size()>k)
                minh.pop();
        }
    cout<<"the k largest elements are-- \n";
    for(int i=0;i<k;i++)
        {
            cout<<minh.top()<<" ";
            minh.pop();
        }
}