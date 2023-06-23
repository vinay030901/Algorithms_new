/*
Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible for every character of str1 to every character of str2 while preserving the order.
Note: All occurrences of every character in str1 should map to the same character in str2

Example 1:

Input:
str1 = aab
str2 = xxy
Output: 1
Explanation: There are two different
charactersin aab and xxy, i.e a and b
with frequency 2and 1 respectively.
Example 2:

Input:
str1 = aab
str2 = xyz
Output: 0
Explanation: There are two different
charactersin aab but there are three
different charactersin xyz. So there
won't be one to one mapping between
str1 and str2.*/

#include <bits/stdc++.h>
using namespace std;
bool areIsomorphic(string str1, string str2)
{

    // Your code here
    unordered_map<char, char> mp12, mp21;
    if (str1.length() != str2.length())
        return false;
    for (int i = 0; i < str1.length(); i++)
    {
        mp12[str1[i]] = str2[i];
        mp21[str2[i]] = str1[i];
    }
    for (int i = 0; i < str1.length(); i++)
    {
        if (mp12[str1[i]] != str2[i] || mp21[str2[i]] != str1[i])
        {
            return false;
        }
    }
    return true;
}