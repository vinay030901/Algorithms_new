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
Output: true*/

#include <bits/stdc++.h>
using namespace std;

// the dp approach is basic here, the only thing we should know is the condition when there is a *
// so when we have a *, we have three choices, whether to increase the number of left bracket, or right bracket or don't do anything
// when we get left bracket, we increase the count and when we get right bracket, we decrease the count
// we have also memoized our approach using a vector
// where we have stored the count and bracket
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

bool checkValidString(string str)
{
    // this method uses stack for its process

    stack<int> bracket, star;
    // the first loop is basic one, if we get open bracket we push it in stack, if get star, then we push it in another stack
    // and if we get closing brack, then we pop the bracket stack or the star stack, if both empty return false
    for (int i = 0; i < str.length(); i++)
    {
        // one think to note is that we are pushing i and not str[i]
        if (str[i] == '(')
            bracket.push(i);
        else if (str[i] == '*')
            star.push(i);
        else
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
    while (!bracket.empty())
    {
        // if star is empty and bracket stack is not, return false
        if (star.empty())
            return false;
        
        // if star is not empty and the star is on the right of the bracket position
        else if (bracket.top() < star.top()){
            bracket.pop();
            star.pop();
        }
        else
            return false;
    }
    return true;
}
int main()
{
}