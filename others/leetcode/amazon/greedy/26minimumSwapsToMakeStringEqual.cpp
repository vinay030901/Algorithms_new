/*
You are given two strings s1 and s2 of equal length consisting of letters "x" and "y" only. Your task is to make these
two strings equal to each other. You can swap any two characters that belong to different strings, which means: swap s1[i] and s2[j].

Return the minimum number of swaps required to make s1 and s2 equal, or return -1 if it is impossible to do so.

Example 1:

Input: s1 = "xx", s2 = "yy"
Output: 1
Explanation: Swap s1[0] and s2[1], s1 = "yx", s2 = "yx".
Example 2:

Input: s1 = "xy", s2 = "yx"
Output: 2
Explanation: Swap s1[0] and s2[0], s1 = "yy", s2 = "xx".
Swap s1[0] and s2[1], s1 = "xy", s2 = "xy".
Note that you cannot swap s1[0] and s1[1] to make s1 equal to "yx", cause we can only swap chars in different strings.
Example 3:

Input: s1 = "xx", s2 = "xy"
Output: -1*/
#include <bits/stdc++.h>
using namespace std;
int minimumSwap(string s1, string s2)
{
    // this question is based on checking the cases rather than thinking
    // so we will check such cases here
    // if length of s1 and s2 are not equal, then they can't be equal, so return -1
    // now we will count the number of errors and number of x or y in s1
    // x- errors which are x in s1, y- errors which are y in s1
    // for cases like 'xx' and 'yy'- the number of x is even here, so we can make a single swap
    // it is like case such as 'xxyy' and 'yyxx' here we can make two swaps, that is (x+y)/2 swaps

    // another case is 'xy' and 'yx' - where no of x on one side is odd, so we need to make two swaps here
    // like the case is 'xxxy' and 'yyyx', so we need to add 1 to (x+y)/2 in this case
    int n = s1.length(), m = s2.length();
    if (n != m)
        return -1;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
        {
            if (s1[i] == 'x')
                x++;
            else
                y++;
        }
    }
    if ((x + y) % 2)
        return -1;
    int ans = (x + y) / 2;
    if (x % 2)
        ans += 1;
    return ans;
}
int main()
{
}