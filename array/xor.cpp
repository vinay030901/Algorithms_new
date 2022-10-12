#include<bits/stdc++.h>
using namespace std;
 
const int N=2e5+5;
int n,a,f,s,t,ans=0,c[N]={0};
int main(){
cin>>n;
for(int i=0;i<n;i++)scanf("%d",&a),c[a]++;
int i=0,j=0;
for(;i<N;i=j){
while(!c[i]&&i<N)i++;
for(j=max(i,j)+1,t=c[i];j<N&&c[j]>1;t+=c[j++]);
if(t+c[j]>ans)ans=t+c[j],f=i,s=j;
}
cout<<ans<<endl;
for(int i=f;i<=s;i++)if(c[i]--)cout<<i<<" ";
for(int i=s;i>=f;i--)for(int j=0;j<c[i];j++)cout<<i<<" ";
}