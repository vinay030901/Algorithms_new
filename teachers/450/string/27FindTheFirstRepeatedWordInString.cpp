/*
Given a string, Find the 1st repeated word in a string
Examples:

Input : "Ravi had been saying that he had been there"
Output : had

Input : "Ravi had been saying that"
Output : No Repetition

Input : "he had had he"
Output : he*/
#include <bits/stdc++.h>
using namespace std;
string findRepeat(string str, int n)
{
    unordered_map<string, int> mp;
    string s = "";
    for (int i = 0; i < n; i++)
    {
        if (str[i] == ' ')
        {
            mp[s]++;
            if (mp[s] == 2)
                return s;
            s = "";
        }
        else
            s += str[i];
    }
    return "";
}
int main()
{
    string str = "Ravi had been saying that he had been there";
    int n = str.length();
    cout << findRepeat(str, n);
}