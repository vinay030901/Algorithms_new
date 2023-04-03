#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={1,2,3,4,5};
    int n=5,sum=0;
    priority_queue<int,vector<int>,greater<int>>minh;
    for(int i=0;i<n;i++)
        minh.push(arr[i]);
    while(minh.size()>=2)
    {
        int m=minh.top();
        minh.pop();
        int n=minh.top();
        minh.pop();
        sum+=(m+n);
        cout<<m<<"+"<<n<<"="<<sum<<endl;
        minh.push((m+n));
    }
    cout<<"sum: "<<sum<<endl;
}