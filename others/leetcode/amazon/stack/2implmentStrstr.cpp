/*
Implement strStr().

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is
not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().


Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1*/
#include <bits/stdc++.h>
using namespace std;
int strStr(string haystack, string needle)
{
    if (needle.size() == 0)
        return 0;
    int n = needle.length();
    int m = haystack.length();
    for (int i = 0; i < m; i++)
    {
        if (haystack[i] == needle[0] && m - i >= n)
        {
            int j = 0;
            for (j = 0; j < n; j++)
            {
                if (needle[j] != haystack[j + i])
                    break;
            }
            if (j == n)
                return i;
        }
    }
    return -1;
}
int main()
{
}