#include<bits/stdc++.h>
using namespace std;
int main()
{    
    int n;
    string a;
    cin>>n;
    vector<string>inarr1(n);
    vector<string>inarr2(n);
    for(int i=0;i<n;i++)
    {
        cin>>inarr1[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>inarr2[i];
    }
    for(int i=0;i<n;i++)
    {
        set<char>s1l,s1n;
        set<int>s2;
        string str1=inarr1[i],str2=inarr2[i],ans="";
        for(int j=0;j<str1.size();j++)
        {
            if(isalpha(str1[j])){
                ans+=str1[j];
            }
            else
            {
                s1n.insert(str1[j]);
            }
        }
    }
}