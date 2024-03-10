/*Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".


Example 1:

Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
Example 2:

Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2


Constraints:

1 <= s.length <= 5 * 104
1 <= words.length <= 5000
1 <= words[i].length <= 50
s and words[i] consist of only lowercase English letters.*/
#include <bits/stdc++.h>
using namespace std;
// Approach 2 : Process by bucket

//       Since length of string s is big,
//              let's think a way to iterate chracters in string s once. We can group words into buckets by their starting character.Then we iterate characters c in string s,
//              we process words in bucket[c] by trimming their starting character : If the word after trimming is empty->then it's a subsequence of string s -> ans += 1. Else group the word after trimming into corresponding buckets by its starting character.
struct Node
{
    int index;
    string word;
    Node(int index, string word) : index(index), word(word) {}
};
class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        vector<Node> buckets[26];
        for (auto it : words)
            buckets[it[0] - 'a'].push_back(Node(0, it));

        int ans = 0;
        for (auto c : s)
        {
            auto currentBucket = buckets[c - 'a'];
            buckets[c - 'a'].clear();
            for (Node &node : currentBucket)
            {
                ++node.index;
                if (node.index == node.word.size())
                    ans++;
                else
                {
                    buckets[node.word[node.index] - 'a'].push_back(node);
                }
            }
        }
        return ans;
    }
};
int main() {}