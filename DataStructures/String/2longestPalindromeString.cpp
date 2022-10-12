#include <bits/stdc++.h>
using namespace std;
void print(string s,int start,int max) {
    for(int i=start;i<max+start;i++)
    {
        cout<<s[i];
    }
    cout<<endl;
}
int longestPalindromeString(string s) {
    int n=s.length();
    bool dp[n][n];
    int start=0,max=1;
    memset(dp,false,sizeof(dp));
    for(int i=0;i<n;i++) {
        dp[i][i]=true;
    }
    if(s.length()==1) return 1;
    else if(s.length()==2){
        if(s[0]==s[1]) return 2;
        else return 1;
    }
    for(int i=0;i<n-1;i++) {
        if(s[i]==s[i+1]) {
            dp[i][i+1]=true;
            start=i;
            max=2;
        }
    }
    for(int k=3;k<=n;++k){
        for(int i=0;i<n-k+1;i++) {
            int j=i+k-1;
            if(s[i]==s[j])
            {
                if(dp[i+1][j-1]==true){
                    start=i;
                    max=k;
                    dp[i][j]=true;
                }
            }
        }
    }
    cout<<start<<endl;
    cout<<max<<endl;
    cout<<"longest palindrome is: ";
    print(s,start,max);
    return max;
}
int main()
{
    string s="abcda";
    int max=longestPalindromeString(s);
    cout<<"length of longest palindromic substring: "<<max<<endl;
}