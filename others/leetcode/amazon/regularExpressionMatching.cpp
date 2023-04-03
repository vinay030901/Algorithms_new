/*
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).



Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".


Constraints:

1 <= s.length <= 20
1 <= p.length <= 30
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.*/
#include <bits/stdc++.h>
using namespace std;
/*so after reading the question, we found out
. -> means it can take any position, means all the single character will match with it
* -> means that we can have the the preceding element as many times as possible
so, a* means -> ["",a,aa,aaa,..]

so one thing we should notice is, this is a dp problem because whenever we get a *, we have two choices, whether to increase the length
that is, take the previous element or not, as we can have elements after that * too

another catch is that we need to find s in p here, so p can take the shape of any string because of * and .

let's take an example:
s=aab
p=c*a*b

i can't make the recursive tree here
so we will start with c(p) and a(s),
c and a doesn't match, so we will move forward in p
then we encounter a (*), so we have choice now, whether to take c again or not, that is move forward
so if we take c, string doesn't match, so we won't move forward with this, and in next we don't take it

now we have a in p and a in s, a in p's next is *, so we have choice to take the a or to leave a
if we leave a, we reach b and that's where noting matches and we reach end
but if we choose a, a in s will match here
so we move forward in s, now it's again a, therefore we choose to use * and it matches a again
if we didn't we reach b, b and a are not same, so false again

now we have matched aa in s using a*, so now we have two choices, take a again or leave a,
so if we repeat a, we get aaa, which is false, and if we not repeat, then we reach b, now b of s and b of p matches
so we reach end of s, and therefore string is matched, therefore string matches

*/
bool dfs(int i, int j, string s, string p, vector<vector<int>> &v)
{
    if (v[i][j] != -1) // memoize
        return v[i][j];
    if (i >= s.length() and j >= p.length()) // so if we cross both string and pattern together, it means true
        return true;
    if (j >= p.length()) // if we cross j, that is length of pattern, that is we are not able to find the characters, and that's why false
        return false;
    bool match = (i < s.length() and (s[i] == p[j] or p[j] == '.')); // now we check if the character matches or not
    if ((j + 1) < p.length() and p[j + 1] == '*') // now we also check if the next is * or not, if it is, we will go for a choice here
        return v[i][j] = ((dfs(i, j + 2, s, p, v) or (match and dfs(i + 1, j, s, p, v))));
        // either to jump to other side or if it matches, we can increase the i value, that is the string value
    if (match == true)
        return v[i][j] = dfs(i + 1, j + 1, s, p, v);
    return v[i][j] = false;
}
bool isMatch(string s, string p)
{

    vector<vector<int>> v(100, vector<int>(100, -1));
    return dfs(0, 0, s, p, v);
}
int main()
{
}