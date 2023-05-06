/*Given a string of lowercase alphabets, count all possible substrings (not necessarily distinct) that has exactly k distinct characters.

Examples:

Input: abc, k = 2
Output: 2
Possible substrings are {“ab”, “bc”}

Input: aba, k = 2
Output: 3
Possible substrings are {“ab”, “ba”, “aba”}

Input: aa, k = 1
Output: 3
Possible substrings are {“a”, “a”, “aa”}*/
#include <bits/stdc++.h>
using namespace std;
int atmost(string &s, int k)
{
    unordered_map<char, int> mp;
    int i = 0, res = 0;
    for (int j = 0; j < s.length(); j++)
    {
        if (!mp[s[j]]++)
            k--;
        while (k < 0)
        {
            if (!--mp[s[i]])
                k++;
            i++;
        }
        res += (j - i + 1);
    }
    return res;
}
int exactlykDistinctChars(string s, int k)
{
    // this solution will become popular sliding window problem with one change
    // if we want something like atmost k distinct characters rather than k distinct characters
    // so to get k distinct characters, we need to subtract atmost k-1 distinct characters from atmost k distinct characters
    return atmost(s, k) - atmost(s, k - 1);
}
int main()
{
    cout << exactlykDistinctChars("abcca", 3);
}