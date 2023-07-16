/*
Given a string S containing only digits, Your task is to complete the function genIp() which returns a vector containing all possible combinations of valid IPv4 IP addresses and takes only a string S as its only argument.
Note: Order doesn't matter. A valid IP address must be in the form of A.B.C.D, where A, B, C, and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.


For string 11211 the IP address possible are
1.1.2.11
1.1.21.1
1.12.1.1
11.2.1.1

Example 1:

Input:
S = 1111
Output: 1.1.1.1
Example 2:

Input:
S = 55
Output: -1*/
#include <bits/stdc++.h>
using namespace std;
vector<string> ans;
void check(string &s, int ind, string out, string temp, int dot, int n)
{
    if (ind > n)
        return;
    if (temp.size() == 3)
        return;
    if (dot > 4)
        return;
    if (ind == n)
    {
        if (dot == 4 && out.size() == n + 4)
        {
            out.pop_back();
            ans.push_back(out);
        }
        return;
    }
    temp += s[ind];
    if (stoi(temp) > 255)
        return;
    if (temp.size() > 1 && temp[0] == '0')
        return;
    check(s, ind + 1, out, temp, dot, n);
    check(s, ind + 1, out + temp + ".", "", dot + 1, n);
}
vector<string> genIp(string &s)
{
    // Your code here
    if (s.length() < 4)
        return {"-1"};
    check(s, 0, "", "", 0, s.length());
    return ans;
}