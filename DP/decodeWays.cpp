#include<bits/stdc++.h>
using namespace std;
int numDecodings(string s) {
        int n=s.length();
        if(n==0||s[0]=='0')
            return 0;
        int dp[n];
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            if(s.substr(i-1,2)=="00")
                dp[i]=0;
            else if(s[i-1]=='0' && s[i]!='0')
                dp[i]=dp[i-1];
            else if(s[i-1]!='0' && s[i]=='0')
            {
                if(s[i-1]=='1' || s[i-1]=='2')
                    dp[i]=(i>=2?dp[i-2]:1);
                else dp[i]=0;
            }
            
            else
            {
                if(stoi(s.substr(i-1,2))<=26)
                    dp[i]=dp[i-1]+(i>=2?dp[i-2]:1);
                else
                    dp[i]=dp[i-1];
            }
        }
        return dp[n-1];
    }
int main()
{

}