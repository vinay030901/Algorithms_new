/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from
magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.



Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true*/
#include <bits/stdc++.h>
using namespace std;
bool canConstruct(string arr1, string arr2)
{
    unordered_map<char, int> m1, m2;
    for (int i = 0; i < arr1.length(); i++)
        m1[arr1[i]]++;

    for (int i = 0; i < arr2.length(); i++)
        m2[arr2[i]]++;
    for (auto it : m1)
    {
        if (it.second > m2[it.first])
            return false;
    }
    return true;
}
int main()
{
}