#include<bits/stdc++.h>
using namespace std;
int m[]={1,5,7,10};
int inf=1e7;
int fun(int n,vector<int>&dp)
{
	if(n==0) return 0;
	if(n<0) return inf;
	if(dp[n]!=-1) return dp[n];
	int mn=inf;
	for(int i=0;i<4;i++)
	{
		if(n>m[i]) continue;
		mn=min(mn,1+fun(n-m[i]))
	}
	dp[n]=mn;
	return mn;
}
int bottles_requried(int n)
{
	vector<int>dp(n+1,-1);
	return fun(n,dp);
}
int main()
{
	int n;
	cin>>n;
	cout<<bottles_requried(n)<<endl;
}