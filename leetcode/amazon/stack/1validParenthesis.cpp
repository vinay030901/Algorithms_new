/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.


Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false*/
#include <bits/stdc++.h>
using namespace std;
bool isValid(string str)
{
    stack<char> st;
    int n = str.length();
    if (n == 1)
        return false;

    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            st.push(str[i]);
        else
        {
            if (st.empty())
                return false;
            else if (str[i] == ')' && st.top() == '(')
                st.pop();
            else if (str[i] == ']' && st.top() == '[')
                st.pop();
            else if (str[i] == '}' && st.top() == '{')
                st.pop();
            else
                return false;
        }
    }
    if (!st.empty())
        return false;
    return true;
}
int main()
{
}