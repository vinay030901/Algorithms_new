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
        Pattern found at index 12*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string txt = "AABAACAADAABAABA";
    string pat = "AABA";

    // the naive approach is to check for every string here, we will use the substr function and traverse the whole
    // text, and if it matches, we will print the index.
    int n = txt.length();
    int m = pat.length();
    for (int i = 0; i <= n - m; i++)
    {
        if (txt.substr(i, m) == pat)
            cout << "found at: " << i << endl;
    }
    // but this approach worst time complexity is O(n^2), so we cant decrease the worst time complexity
    // but we can decrease the number of comparisons, here every substring is taken

    /*in rabin karp we will first calculate the hash of the string that is to compared with our pattern,
    and if the hash matches, then we will compare all the value, it will drastically decrease the time complexity

    since we need to efficeintly calculate the hash function, we will use an algorithm with the help of which we
    will calculate the value of next hash using the present hash function.
    so we take off the most significant digit and add the new digit
    hash( txt[s+1 .. s+m] ) = ( d ( hash( txt[s .. s+m-1]) – txt[s]*h ) + txt[s + m] ) mod q
    hash( txt[s .. s+m-1] ) : Hash value at shift s.
    hash( txt[s+1 .. s+m] ) : Hash value at next shift (or shift s+1)
    d: Number of characters in the alphabet
    q: A prime number
    h: d^(m-1)*/

    int d = 256; 
    int prime = 101; // we use a prime number to calculate the modulus
    int h = 1, p = 0, t = 0;

    // calculate the basic hash funciton
    // the value of basic hash funciton is pow(d,m-1)
    // h is like h, when in a string of 23456, we have 234, we want 345, then we do (234-2*100)*10+5-> h is 100 here
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % prime;

    // calculating the first window
    for (int i = 0; i < m; i++)
    {
        p = (d * p + pat[i]) % prime;
        t = (d * t + txt[i]) % prime;
    }
    for (int i = 0; i <= n - m; i++)
    {
        if (t == p)
        {
            int j = 0;
            for (j = 0; j < m; j++)
            {
                if (pat[j] != txt[i + j])
                    break;
            }
            if (j == m)
                cout << "pattern found at index at: " << i << endl;
        }
        // to match for the pattern next, we need to move to other window
        if (i < n - m)
        {
            t = ((t - txt[i] * h) * d + txt[i + m]) % prime;
            // the catch here is that for example, we have a string "23456", the first hash we calculated is 234
            // so we need to 345 now, to make it 345, we will do
            // t=(( 234(t)- 2(txt[i])*100(h))*10(d) + 5(txt[i+m]))

            // we might get a negative value with it, so to cover it, we will make it positive
            if (t < 0)
                t = t + prime;
        }
    }
    return 0;
}