/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words
beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence
from beginWord to endWord, or 0 if no such sequence exists.



Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.*/
#include <bits/stdc++.h>
using namespace std;
/*
so we need to find the shortest path from beginWord to endWord here
HOW THIS IS A GRAPH PROBLEM:
assume each word as node in graph and each transformation as edge

the solution of problem is pretty basic, we will use bfs in this, means every incoming string is going to compared with
the those element which is equal to that string but with a single character changed, and if that element is present in the wordList
then it like our adjacent node, so we push it in the queue
if that adjacent node is end word, then we return time+1;

checking if the element is present or not is done using set in average O(1) time.
*/
int ladderLength(string beginWord, string endWord, vector<string> &words)
{
    unordered_set<string> s;
    int n = words.size();
    bool isPresent = false;
    for (int i = 0; i < n; i++)
    {
        if (words[i] == endWord)
            isPresent = true;
        s.insert(words[i]);
    }
    if (isPresent == false)
        return 0;
    int time = 0;
    queue<string> q;
    q.push(beginWord); // pushing the begin word first to check for its adjacent node
    int len = beginWord.length();
    while (!q.empty())
    {
        int lsize = q.size();
        time++;
        while (lsize--)
        {
            string str = q.front();
            q.pop();
            for (int i = 0; i < len; i++) // traversing the string to change the character at every position
            {
                string s2 = str;
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    s2[i] = ch;
                    if (s2 == endWord)
                        return time + 1;
                    if (s.find(s2) != s.end())
                    {
                        q.push(s2);
                        s.erase(s2);
                    }
                }
            }
        }
    }
    return 0;
}
int main()
{
}