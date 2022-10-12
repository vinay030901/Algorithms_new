#include<bits/stdc++.h>
using namespace std;
bool isSafe(int **arr,int x,int col,int n)
{
    for(int row=0;row<x;row++)
    {
        if(arr[row][col]==1)
            return false;
    }
    int i=x;
    int j=col;
    while(i>=0 && j>=0)
    {
        if(arr[i][j]==1)
            return false;
        i--;
        j--;
    }
    i=x;
    j=col;
    while (i>=0 && j<n)
    {
        if(arr[i][j]==1)
            return false;
        i--;
        j++;
    }
    return true;
}
bool NQueen(int **arr,int x,int n)
{
    if(x>=n)
    return true;
    for(int col=0;col<n;col++)
    {
        if(isSafe(arr,x,col,n))
        {arr[x][col]=1;
        cout<<"for x="<<x<<" and col="<<col<<"\n";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<arr[i][j]<<" ";
            cout<<"\n";
        }
        if(NQueen(arr,x+1,n))
            return true;
        arr[x][col]=0;
        cout<<"after backtracking for x ="<<x<<" and col="<<col<<"\n";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<arr[i][j]<<" ";
            cout<<"\n";
        }}}
    cout<<"out of loop\n";
    return false;
}
int main()
{
    int n;
    cin>>n;
    int **arr= new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
        for(int j=0;j<n;j++)
            arr[i][j]=0;
    }
    bool c=NQueen(arr,0,n);
    cout<<"last:   \n";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<arr[i][j]<<" ";
            cout<<"\n";
        }
}