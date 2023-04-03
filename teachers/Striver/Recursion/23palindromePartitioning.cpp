/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> ans;
bool isPalindrome(string str, int start, int end)
{
    while (start <= end)
    {
        if (str[start++] != str[end--])
            return false;
    }
    return true;
}
void fun(string s, int start, int n, vector<string> &path)
{
    if (start == n)
    {
        ans.push_back(path);
        return;
    }
    for (int end = start; end < n; end++) // traversing the string and checking if the string is palindrome from start till end
    {
        // we will only take the element when it is a palindrome
        if (isPalindrome(s, start, end))
        {
            path.push_back(s.substr(start, end - start + 1));
            fun(s, end + 1, n, path);// now end+1 will be our start
            path.pop_back(); // backtracking step
        }
    }
}
vector<vector<string>> partition(string s)
{
    vector<string> v;
    fun(s, 0, s.length(), v);
    return ans;
}
int main()
{
}