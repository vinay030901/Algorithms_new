/*Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

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
Explanation: s becomes "c" while t becomes "b".


Constraints:

1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.


Follow up: Can you solve it in O(n) time and O(1) space?*/
#include <bits/stdc++.h>
using namespace std;
bool backspaceCompare(string s, string t)
{
    string s1 = "", s2 = "";
    for (auto it : s)
        if (it == '#')
        {
            if (!s1.empty())
                s1.pop_back();
        }
        else
            s1 += it;
    for (auto it : t)
        if (it == '#')
        {
            if (!s2.empty())
                s2.pop_back();
        }
        else
            s2 += it;
    cout << s1 << " " << s2;
    return s1 == s2;
}
bool backspaceCompare1(string s, string t)
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
    // Your code here
    return 0;
}
