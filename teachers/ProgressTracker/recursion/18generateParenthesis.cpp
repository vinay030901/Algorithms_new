#include <bits/stdc++.h>
using namespace std;
vector<string> ans;
void count(int open, int close, string str)
{
    if (open == 0 && close == 0)
    {
        ans.push_back(str);
        return;
    }
    if (open == 0)
    {
        string s = "";
        for (int i = 0; i < close; i++)
            s += ')';
        ans.push_back(str + s);
        return;
    }
    if (open == close)
        count(open - 1, close, str + '(');
    else
    {

        count(open - 1, close, str + '(');
        count(open, close - 1, str + ')');
    }
}
vector<string> generateParenthesis(int n)
{
    string str = "";
    count(n, n, str);
    return ans;
}