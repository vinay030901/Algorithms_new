/*Given a string s, return true if the s can be palindrome after deleting at most one character from it.
Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false


Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.*/
#include <bits/stdc++.h>
using namespace std;
bool check(string s, int i, int j)
{
    while (i <= j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
bool validPalindrome(string s)
{
    int odd = 0, f = 0;
    int n = s.length();
    int i = 0, j = n - 1;
    while (i <= j)
    {
        if (s[i] != s[j])
        {
            bool ans = check(s, i + 1, j);
            if (!ans)
                return check(s, i, j - 1);
            return ans;
        }
        i++;
        j--;
    }
    return true;
}
int main()
{
    // Your code here
    return 0;
}