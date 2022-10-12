#include<bits/stdc++.h>
using namespace std;
int maxarea(int arr[],int n)
{
    stack<int>s;
    vector<int>left(n),right;
    for(int i=0;i<n;i++)
    {
        if(s.empty())
        left[i]=-1;
        else
        while(!s.empty() && arr[s.top()]>=arr[i])
        s.pop();
        if(s.empty())
        left[i]=-1;
        else
        left[i]=s.top();
        s.push(i);
    }
    for(int i=0;i<n;i++)
    cout<<left[i]<<"  ";
    cout<<endl;
    stack<int>s1;
    for(int i=n-1;i>=0;i--)
    {
        if(s1.empty())
        right.push_back(n);
        else
        while(!s1.empty() && arr[s1.top()]>=arr[i])
        s1.pop();
        if(s1.empty())
        right.push_back(n);
        else
        right.push_back(s1.top());
        s1.push(i);
    }
    reverse(right.begin(), right.end());
    for(int i=0;i<n;i++)
    cout<<right[i]<<"  ";
    cout<<endl;
    // calculating width
    for(int i=0;i<n;i++)
    left[i]=right[i]-left[i]-1;
    int mx=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int x=left[i]*arr[i];
        cout<<x<<"  ";
        mx=max(x,mx);
    }
    return mx;
}
int main()
{
    int arr[]={7,2,8,9,1,3,6,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans=maxarea(arr,n);
    cout<<ans;
}