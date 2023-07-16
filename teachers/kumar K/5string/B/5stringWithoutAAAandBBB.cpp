/*
Given two integers a and b, return any string s such that:

s has length a + b and contains exactly a 'a' letters, and exactly b 'b' letters,
The substring 'aaa' does not occur in s, and
The substring 'bbb' does not occur in s.


Example 1:

Input: a = 1, b = 2
Output: "abb"
Explanation: "abb", "bab" and "bba" are all correct answers.
Example 2:

Input: a = 4, b = 1
Output: "aabaa"*/
#include <bits/stdc++.h>
using namespace std;
string fun(string more, string less, int moredig, int lessdigit)
{
    int diff = moredig - lessdigit;
    string str = "";
    for (int i = 0; i < lessdigit; i++)
    {
        if (diff)
        {
            str += (more + more + less);
            diff--;
        }
        else
        {
            str += (more + less);
        }
    }
    if (diff == 1)
        str += more;
    else if (diff == 2)
        str += (more + more);
    return str;
}
string strWithout3a3b(int a, int b)
{
    if (a >= b)
        return fun("a", "b", a, b);
    return fun("b", "a", b, a);
}
int main()
{
}