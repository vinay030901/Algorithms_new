#include<bits/stdc++.h>
using namespace std;
int operation(int a,int b,char c)
{
	if(c=='*')
	return a*b;
	else if(c=='+')
	return a+b;
	else if(c=='-')
	return a-b;
	else
	return a/b;
}
int main()
{
	int n;
	cin>>n;
	stack<int>sti;
	stack<char>stc;
	for(int i=0;i<n;i++)
	{
		char c;
		cin>>c;
		if(isdigit(c))
		sti.push(c-'0');
		else
		{
			int a=sti.top();
            
			sti.pop();
			int b=sti.top();
			sti.pop();
			int ans=operation(b,a,c);
			sti.push(ans);
            cout<<"i: "<<i<<" a: "<<a<<" b: "<<b<<" ans: "<<ans<<endl;
		}
	}
	cout<<sti.top();
}