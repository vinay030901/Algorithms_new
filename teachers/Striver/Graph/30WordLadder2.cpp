0/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words
beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from
beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words
[beginWord, s1, s2, ..., sk].

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> ans;
void dfs(string &beginWord, string &endWord, unordered_map<string, unordered_set<string>> &adj, vector<string> &path)
{
    // here we are using dfs and backtracking
    // push the string first and then check if it is equal to endWord here, if it is we return our string
    path.push_back(beginWord);
    if (beginWord == endWord)
    {
        ans.push_back(path);
        // after pushing path in answer, we pop back
        path.pop_back();
        return;
    }
    for (auto x : adj[beginWord])
    {
        // here, we are calling for the dfs
        dfs(x, endWord, adj, path);
    }
    path.pop_back();
}
// the code might be difficult here, what we are doing here is first doing bfs and then dfs
// bfs is done to find the depth of every node as well as child of every node here
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &words)
{
    unordered_set<string> dict(words.begin(), words.end()); // we take the dictionary set to search for any word in average constant time
    if (dict.find(endWord) == dict.end())                   // return null if don't have the last word
        return ans;
    int n = words.size();
    unordered_map<string, unordered_set<string>> adj; // map working as a parent, the unordered set is the list of childs
    // we are making this because we don't want our path to go back while checking, so it will only move to side of its childs
    queue<string> q;
    bool found = false;
    q.push(beginWord);
    unordered_map<string, int> vis; // visited map is to map the depth of every node here
    vis[beginWord] = 0;
    while (!q.empty())
    {
        // we do work similar to word ladder at the start
        string str = q.front();
        q.pop();
        string temp = str;
        for (int i = 0; i < str.size(); i++)
        {
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                if (temp[i] == ch)
                    continue;
                temp[i] = ch;
                if (temp == endWord)
                {
                    found = true;
                }
                // so if we find the word present in the dictionary, we will check if is already visited or not
                if (dict.count(temp) > 0)
                {
                    if (vis.count(temp) == 0) // if not visited, we put it in queue, map its depth and put in adjacent list
                    {
                        vis[temp] = vis[str] + 1;
                        q.push(temp);
                        adj[str].insert(temp);
                    }
                    else if (vis[temp] == vis[str] + 1) // if already visited, we only put it in adjacency list
                        adj[str].insert(temp);
                }
            }
            temp[i] = str[i]; // revert back temp to curr
        }
    }
    if (found == false)
        return ans;
    vector<string> path;
    dfs(beginWord, endWord, adj, path);
    return ans;
}
int main()
{
}