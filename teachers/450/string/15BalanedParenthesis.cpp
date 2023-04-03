/*
Given an expression string exp, write a program to examine whether the pairs and the orders of “{“, “}”, “(“, “)”, “[“, “]” 
are correct in exp.

Example:

Input: exp = “[()]{}{[()()]()}”
Output: Balanced

Input: exp = “[(])”
Output: Not Balanced */
#include <bits/stdc++.h>
using namespace std;
bool checkParentheses(string str, int n)
{
    stack<char> st;
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
    string str = "[()]{}{[()[()]()}";
    int n = str.length();

    /*to check for balanced parentheses, we will make use of stack,
    here we will traverse the string, and put the brackets in stack,
    at first, we should get opening brackets, while the opening brackets, we will put them in stack,
    and when the closing bracket is encountered, we will check if the top of our stack is the closing form of the
    same bracket or now, if it is, we will pop the bracket and move on and if it isn't we will return unbalanced

    so for the above string,
    [ comes, ( comes in stack, now we encounter ')'
    check for top of stack, we have '(' so we will pop this and keep on adding other,
    next we have ']' we have '[' as stack top, so pop it

    after the whole traversal if we still have brackets in the stack, then also we will return unbalanced*/

    if (checkParentheses(str, n))
        cout << "balanced brackets";
    else
        cout << "unbalanced brackets";
}