/*
Given two strings A and B, you need to find the last occurrence ( 1 based indexing) of string B in string A.
Example 1:

Input:
A = abcdefghijklghifghsd
B = ghi
Output:
13
Explanation:
ghi occurs at position 13 for the
last time in string A.
Example 2:

Input:
A = abdbccaeab
B = abc
Output:
-1
Explanation:
abc is not a substring of A*/
#include <bits/stdc++.h>
using namespace std;
void createLps(vector<int> &lps, int m, string b)
{
    int len = 0, i = 1;
    while (i < m)
    {
        if (b[i] == b[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
                len = lps[len - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
int findLastOccurence(string a, string b)
{
    int n = a.length(), m = b.length();
    vector<int> lps(m);
    createLps(lps, m, b);
    int i = 0, j = 0, ans = -1;
    while ((n - i) >= (m - j))
    {
        if (a[i] == b[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            ans = i - j + 1;
            j = lps[j - 1];
        }
        else if (i < n && a[i] != b[j])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return ans;
}
int main()
{

    return 0;
}