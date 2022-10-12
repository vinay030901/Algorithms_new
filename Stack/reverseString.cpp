#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str="the champ is here";
    stack<char>st;
    for(int i=0;i<str.length();i++)
    {
        st.push(str[i]);
    }
    string ans="";
    for(int i=0;i<str.length();i++)
    {
        ans.push_back(st.top());
        st.pop();
    }
    cout<<ans;
}