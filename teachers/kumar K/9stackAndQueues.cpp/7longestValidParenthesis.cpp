/*
Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses
substring
Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0*/
#include <bits/stdc++.h>
using namespace std;
int longestValidParentheses(string s)
{
    stack<int> st;
    int ans = 0;
    st.push(-1);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            st.push(i);
        else
        {
            if (!st.empty() && st.top() != -1 && s[st.top()] == '(')
            {
                st.pop();
                ans = max(ans, i - st.top());
            }
            else
                st.push(i);
        }
    }
    return ans;
}
int main()
{

    return 0;
}