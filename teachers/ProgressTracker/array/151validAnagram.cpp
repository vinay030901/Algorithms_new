/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false


Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.


Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?*/
#include <bits/stdc++.h>
using namespace std;
bool isAnagram(string s, string t)
{
    vector<int> mp1(26, 0), mp2(26, 0);
    for (auto it : s)
        mp1[it - 'a']++;
    for (auto it : t)
        mp2[it - 'a']++;
    return mp1 == mp2;
}
int main()
{
    // Your code here
    return 0;
}