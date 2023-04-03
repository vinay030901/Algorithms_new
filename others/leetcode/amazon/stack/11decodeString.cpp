/*
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times.
Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc.
Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k.
For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.



Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"*/
#include <bits/stdc++.h>
using namespace std;
string helper(int &pos, string s)
{
    int num = 0;
    string word = "";
    for (; pos < s.size(); pos++)
    {
        char c = s[pos];
        if (c == '[')
        {
            string cur = helper(++pos, s);
            for (; num > 0; num--)
                word += cur;
        }
        else if (c >= '0' && c <= '9')
            num = num * 10 + (c - '0');
        else if (c == ']')
            return word;
        else
            word += c;
    }
    return word;
}
string decodeString(string s)
{
    int pos = 0;
    return helper(pos, s);
}
int main()
{
}