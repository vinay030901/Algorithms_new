/*You are given an array of words where each word consists of lowercase English letters.

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
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.*/\
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestStrChain(vector<string> &words)
    {
        unordered_map<string, int> mp;
        sort(words.begin(), words.end(), [&](const string str1, const string str2)
             { return str1.size() < str2.size(); });
        int res = 0;
        for (auto w : words)
        {
            mp[w] = 1;
            for (int i = 0; i < w.length(); i++)
            {
                string str = w;
                str.erase(str.begin() + i);
                if (mp.find(str) != mp.end() && mp[str] + 1 > mp[w])
                    mp[w] = mp[str] + 1;
            }
            res = max(res, mp[w]);
        }
        return res;
    }
};
int main() {
    // Your code here
    return 0;
}