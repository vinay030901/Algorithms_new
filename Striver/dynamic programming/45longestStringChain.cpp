/*
You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.



Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
Example 3:

Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.


Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of lowercase English letters.*/

#include <bits/stdc++.h>
using namespace std;
static bool comparator(string &s1, string &s2)
{
    return s1.size() < s2.size();
}
bool compare(string &s1, string &s2)
{
    if (s1.size() != s2.size() + 1)
        return false;
    int first = 0, second = 0;
    while (first < s1.size())
    {
        if (s1[first] == s2[second])
        {
            ++first;
            ++second;
        }
        else
            first++;
    }
    if (first == s1.size() && second == s2.size())
        return true;
    else
        return false;
}
int longestStrChain(vector<string> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end(), comparator);
    vector<int> lis(n, 1);
    int mx = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (compare(arr[i], arr[j]) && lis[i] < lis[j] + 1)
            {
                lis[i] = lis[j] + 1;
            }
        }
        mx = max(mx, lis[i]);
    }
    return mx;
}
int main()
{
}