#include <bits/stdc++.h>
using namespace std;
void computeLps(vector<int> &lps, int m, string pat)
{
    int len = 0, i = 1;
    while (i < m)
    {
        if (pat[i] == pat[len])
        {
            lps[i] = len + 1;
            len++;
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
void kmp(string text, string pat)
{
    // we are looking for longest prefix suffix
    int n = text.length(), m = pat.length();
    vector<int> lps(m, 0);
    computeLps(lps, m, pat);
    int i = 0, j = 0;
    while (i < n)
    {
        if (text[i] == pat[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i += 1;
        }
        if (j == m)
        {
            cout << i - j << " ";
            j = lps[j - 1];
        }
    }
}
int main()
{
}