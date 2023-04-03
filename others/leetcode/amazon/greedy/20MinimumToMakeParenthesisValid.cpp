/*
A parentheses string is valid if and only if:

It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
Return the minimum number of moves required to make s valid.

Example 1:

Input: s = "())"
Output: 1
Example 2:

Input: s = "((("
Output: 3*/
#include <bits/stdc++.h>
using namespace std;
int minAddToMakeValid(string s)
{
    int n = s.length(), left = 0, right = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            left++; // open bracket
        else if (left > 0)
            left--; // closing the bracket
        else
            right++; // there's no open bracket for this closed bracket, so we increment
    }
    return left + right;
}
int main()
{
}