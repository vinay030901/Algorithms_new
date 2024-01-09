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

// solution without if condition
vector<string> ans;
void generate(string str, int s, int e)
{
    if (!s && !e)
    {
        ans.push_back(str);
        return;
    }
    if (s < e)
    {
        if (s)
            generate(str + "(", s - 1, e);
        generate(str + ")", s, e - 1);
    }
    else if (s == e)
        generate(str + "(", s - 1, e);
}
vector<string> generateParenthesis(int n)
{
    generate("", n, n);
    return ans;
}