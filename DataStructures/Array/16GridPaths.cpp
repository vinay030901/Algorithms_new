/*count the number of ways you can go move from start to end
approach 1 would be to use recursion or dynamic programming, that will show us the ways in whihc we can travel by moving right or down
other approach would be to use combination techniques to find the number of combinations*/
#include<bits/stdc++.h>
using namespace std;
//memoised approach
int countPaths(int i,int j,int m,int n)
{
    if(i==m-1 && j==n-1)
        return 1;
    else if(i>=m && j>=n)
        return 0;
    else
    return countPaths(i,j+1,m,n)+countPaths(i+1,j,m,n);
}
int main()
{
    int m=3,n=2;
    int r=m-1;
    //cout<<countPaths(0,0,m,n);
    int num=m+n-2;
    double res=1;
    for(int i=1;i<=r;i++)
        {res=res*(num-r+i)/i;
        cout<<"res= "<<res<<" i="<<i<<endl;}
    cout<<num<<" "<<endl;
    cout<<int(res);
    }