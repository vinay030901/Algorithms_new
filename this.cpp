#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    int a1[256]={0},a2[256]={0};
    for(int i=0;i<n;i++) a1[s1[i]]++;
    for(int i=0;i<n;i++) a2[s2[i]]++;
    bool ans=true;
    for(int i=0;i<256;i++) if(abs(a1[i] - a2[i])>3) ans=false;
    if(ans==false) cout<<"-1";
    else
    {
        if(s1<s2) cout<<s1;
        else cout<<s2;
    }
    
}
