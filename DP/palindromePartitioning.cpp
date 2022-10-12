#include <bits/stdc++.h>
using namespace std;
int static t[501][501];
    bool ispalindrome(string s,int i,int j)
    {
        if(i>=j)
            return true;
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string s,int i,int j)
    {
        if(t[i][j]!=-1)
            return t[i][j];
        if(i>=j)
            return 0;
        if(ispalindrome(s,i,j)==true)
            return 0;
        int mn=INT_MAX;
        for(int k=i;k<=j-1;k++)
        {
            int temp=solve(s,i,k)+solve(s,k+1,j)+1;
            mn=min(temp,mn);
        }
        return t[i][j]=mn;
    }
    int palindromicPartition(string str)
    {
        memset(t,-1,sizeof(t));
        int n=solve(str,0,str.length()-1);
        return n;
    }
int main()
{
    string s="ababbbabbababa";
    cout<<palindromicPartition(s);
}