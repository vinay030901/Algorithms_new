/*
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.



Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".*/
#include <bits/stdc++.h>
using namespace std;
// here we are starting from end rather than start
// so if we encounter a #, then we count the number of skips we have to do

bool backspaceCompare(string s, string t)
{
    int i = s.length() - 1, j = t.length() - 1;
    int skipi = 0, skipj = 0;
    while (i >= 0 || j >= 0)
    {
        while (i >= 0)
        {
            if (s[i] == '#')
            {
                skipi++;
                i--;
            }
            else if (skipi > 0)
            {
                skipi--;
                i--;
            }
            else
                break;
        }
        while (j >= 0)
        {
            if (t[j] == '#')
            {
                skipj++;
                j--;
            }
            else if (skipj > 0)
            {
                skipj--;
                j--;
            }
            else
                break;
        }
        if (i >= 0 && j >= 0 && s[i] != t[j])
            return false;
        if ((i >= 0) != (j >= 0))
            return false;
        i--;
        j--;
    }
    return true;
}
int main()
{
}