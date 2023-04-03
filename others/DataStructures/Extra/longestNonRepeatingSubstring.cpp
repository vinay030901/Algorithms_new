#include<bits/stdc++.h>
using namespace std;
int longestRepeatingSubsequence(string s)
{
    int maxlen=0,l=0;
    map<char,int>mp;
    for(int i=0;i<s.length();i++)
    {
        if(!(mp.count(s[i])))
            mp[s[i]]=i;
        else
        {
            maxlen=max(maxlen,i-mp[s[i]]);
            i=mp[s[i]]+1;
        }    
    }
    cout<<maxlen<<endl;
}
int main()
{
    
}