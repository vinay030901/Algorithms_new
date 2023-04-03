/*
Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], char txt[]) that prints all occurrences of pat[] in txt[]. You may assume that n > m.

Examples:

Input:  txt[] = "THIS IS A TEST TEXT"
        pat[] = "TEST"
Output: Pattern found at index 10

Input:  txt[] =  "AABAACAADAABAABA"
        pat[] =  "AABA"
Output: Pattern found at index 0
        Pattern found at index 9
        Pattern found at index 12
*/

#include <bits/stdc++.h>
using namespace std;
void computeLps(char *pat, int m, int *lps)
{
    int len = 0, i = 1;
    lps[0] = 0;
    while (i < m)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void kmpsearch(char *txt, char *pat)
{
    int n = strlen(txt);
    int m = strlen(pat);
    int lps[m];
    computeLps(pat, m, lps);
    int i = 0, j = 0;
    while (i < n)
    {
        if (txt[i] == pat[j])
        {
            j++;
            i++;
        }
        if (j == m)
        {
            cout << "found at index: " << i-j << endl;
            j = lps[j - 1];
        }
        else if (i < n && pat[j] != txt[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
                i=i+1;
        }
    }
}
int main()
{
    /*the pattern of kmp is that we need to find the prefix which is the same as the suffix
    as we don't want to search all over again.
    In the next step, we compare next window of txt with pat.
    txt = "AAAAABAAABA"
    pat =  "AAAA" [Pattern shifted one position]
    This is where KMP does optimization over Naive. In this
    second window, we only compare fourth A of pattern
    with fourth character of current window of text to decide
    whether current window matches or not. Since we know
    first three characters will anyway match, we skipped
    matching first three characters.

    here we prepare max prefix table, pi table

    a b c d a b e a b f
    0 0 0 0 1 2 0 1 2 0- so a and b appeared two times, and therfore we marked them for prefix values

    a b c d e a b f a b c
    0 0 0 0 0 1 2 0 1 2 3- here c appeared too

    a a a a b a a c d
    0 1 2 3 0 1 2 0 0

    so let's have an example-
    pat - a b a b d
          0 0 1 2 0

    txt - a b a b c a b c a b a b a b d

    for single example- we will compare pat with txt first and then we see that they are not matching at index 5(one based index)
    but since we were at b and we see that b value in pi table is 2, we will return to index 2.
    then 5 value is compared with pat(3), it doesn't match, so move to 1st index

    so txt index is not moving a pat index is moving only

    */
    char txt[] = "ababcababdcabababd";
    char pat[] = "ababd";
    kmpsearch(txt, pat);
}