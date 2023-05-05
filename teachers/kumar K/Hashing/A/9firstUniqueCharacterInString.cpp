/*
simple solution is to traverse the string and create a map of it
then we need to traverse the string again and check if the particular element has frequency 1*/
/*QUESTION

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1*/

#include <bits/stdc++.h>
using namespace std;
int firstUniqChar(string s)
{
    unordered_map<char, int> mp;
    for (auto it : s)
        mp[it]++;
    for (auto it : s)
        if (mp[it] == 1)
            return it;
    return -1;
}