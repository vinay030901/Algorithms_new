/*
Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.

Note: The final output will be in lexicographic order.

Example 1:

Input:
N = 5
words[] = {act,god,cat,dog,tac}
Output:
act cat tac
god dog
Explanation:
There are 2 groups of
anagrams "god", "dog" make group 1.
"act", "cat", "tac" make group 2.
Example 2:

Input:
N = 3
words[] = {no,on,is}
Output:
is
no on
Explanation:
There are 2 groups of
anagrams "is" makes group 1.
"no", "on" make group 2.*/

#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> Anagrams(vector<string> &strs)
{
    map<map<char, int>, vector<string>> mp;
    for (auto str : strs)
    {
        map<char, int> temp;
        for (auto i : str)
            temp[i]++;
        mp[temp].push_back(str);
    }
    vector<vector<string>> ans;
    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}