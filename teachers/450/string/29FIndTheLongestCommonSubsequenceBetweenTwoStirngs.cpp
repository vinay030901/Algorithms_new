/*
LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them. 
A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.
 For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”. 

 this is a classic dp problem and has so many important variatons with it*/

#include<bits/stdc++.h>
using namespace std;
int lcs(string str1, string str2,int n,int m)
{
    //  in recur approach, we will test for all the possibilities of the answer, 
    // if both the character matches, we will decrease both of the length, and if it doesn't we will
    // check for the case when str1 length decrease and str2 length decrease, and the answer would be the larger of them

    if(n==0 || m==0) return 0;// if either of them become zero, we will return 0 as we don't have to check for more Now
    else if(str1[n-1]==str2[m-1]) return 1+lcs(str1,str2,n-1,m-1);
    else return max(lcs(str1, str2,n-1,m),lcs(str1,str2,n,m-1));
}

// now we can optimize the above approach by introducing a 2D array here
int mem[10001][10001];
int lcsmemoize(string str1, string str2,int n,int m)
{
    if(n==0 || m==0) return 0;// if either of them become zero, we will return 0 as we don't have to check for more Now
    if(mem[n][m]!=-1) return mem[n][m];
    else if(str1[n-1]==str2[m-1]) return mem[n][m]=1+lcs(str1,str2,n-1,m-1);
    else return mem[n][m]=max(lcs(str1, str2,n-1,m),lcs(str1,str2,n,m-1));
}
int lcstable(string str1,string str2,int n,int m)
{
    // so we can convert the recursive approach into the dp table easily
    // but first we need to do some initialsation regarding that
    if(n==0 || m==0) return 0; // we know that if either length is zero, the answer is zero

    int dp[n+1][m+1]={0};
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int i=0;i<=m;i++) dp[0][i]=0;

    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        if(str1[i-1]==str2[j-1]) dp[i][j]=1+dp[i-1][j-1];
        else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    return dp[n][m];
}
int main()
{
    string str1="abac",str2="cab";
    // recursive approach 
    int n=str1.length(),m=str2.length();
    cout<<"answer using recursive approach: "<<lcs(str1,str2,n,m);

    // using memoization approach
    memset(mem,-1,sizeof(mem));
    cout<<"\nanswer using memoization approach: "<<lcsmemoize(str1,str2,n,m);

    // using tabulation approach
    cout<<"\nanswer using tabulation approach: "<<lcstable(str1,str2,n,m);
}