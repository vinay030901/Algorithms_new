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
    // calculating width
    for(int i=0;i<n;i++)
    left[i]=right[i]-left[i]-1;
    int mx=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int x=left[i]*arr[i];
        //cout<<x<<"  ";
        mx=max(x,mx);
    }
    cout<<endl;
    return mx;
}
int main()
{
    vector<vector<int>>arr{{0,1,1,0},{1,1,1,1},{1,1,1,1,1},{1,1,0,0}};
    cout<<"the vector is: "<<endl;
    for(int i=0;i<4;i++)
    for(int j=0;j<arr[i].size();j++)
    cout<<arr[i][j]<<" ";
    cout<<endl;
    int n=arr.size();
    int v[n]={0};
    int mx=INT_MIN; 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==0)
            v[j]=0;
            else
            v[j]=arr[i][j]+v[j];
        }
        cout<<"v: \n"; 
        for(int l=0;l<n;l++)
        cout<<v[l]<<"  ";
        cout<<endl;
        int ans=maxarea(v,n);
        mx=max(mx,ans);
    }
    cout<<mx;
}