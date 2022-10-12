/*
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".


Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "(*)"
Output: true
Example 3:

Input: s = "(*))"
Output: true


Constraints:

1 <= s.length <= 100
s[i] is '(', ')' or '*'.*/
#include <bits/stdc++.h>
using namespace std;

// solution 1
bool check(string str, int bracket, int i, vector<vector<int>> &v)
{
    if (bracket < 0)
        return false;
    if (i == str.size())
        return bracket == 0;
    if (v[bracket][i] != -1)
        return v[bracket][i];
    if (str[i] == '(')
        return v[bracket][i] = check(str, bracket + 1, i + 1, v);
    else if (str[i] == ')')
        return v[bracket][i] = check(str, bracket - 1, i + 1, v);
    else
        return v[bracket][i] = (check(str, bracket + 1, i + 1, v) || check(str, bracket, i + 1, v) || check(str, bracket - 1, i + 1, v));
    return false;
}
bool checkValidString(string s)
{
    vector<vector<int>> v(110, vector<int>(110, -1));
    return check(s, 0, 0, v);
}

// solution 2
bool checkValidString(string str)
{
    stack<int> bracket;
    stack<int> star;
    // the first loop is basic one, if we get open bracket we push it in stack, if get star, then we push it in another stack
    // and if we get closing brack, then we pop the bracket stack or the star stack, if both empty return false
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
            bracket.push(i);
        if (str[i] == '*')
            star.push(i);
        if (str[i] == ')')
        {
            if (!bracket.empty())
                bracket.pop();
            else if (!star.empty())
                star.pop();
            else
                return false;
        }
    }

    // if bracket stack is not empty, at the end, we will use loop
    while (!bracket.empty() && !star.empty())
    {
        if (bracket.top() > star.top())
            return false;

        bracket.pop();
        star.pop();
    }
    return bracket.empty();
}
int main()
{
}