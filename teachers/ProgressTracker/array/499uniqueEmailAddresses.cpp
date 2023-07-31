#include <bits/stdc++.h>
using namespace std;
unordered_set<string> st;
void fun(string str)
{
    string end = "";
    int i = 0;
    while (i < str.length() && str[i] != '+' && str[i] != '@')
    {
        if (str[i] == '.')
            i++;
        else
            end += str[i++];
    }
    while (i < str.length() && str[i] != '@')
        i++;
    end += str.substr(i);
    st.insert(end);
}
int numUniqueEmails(vector<string> &emails)
{
    for (auto it : emails)
        fun(it);
    return st.size();
}