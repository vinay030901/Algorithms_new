/*
Given a number n, find the smallest number that has same set of digits as n and is greater than n.
If n is the greatest possible number with its set of digits, then print “not possible”.

Examples:
For simplicity of implementation, we have considered input number as a string.

Input:  n = "218765"
Output: "251678"

Input:  n = "1234"
Output: "1243"

Input: n = "4321"
Output: "Not Possible"

Input: n = "534976"
Output: "536479"

Input: n = "258764"
Output: "264578"*/
#include <bits/stdc++.h>
using namespace std;
string nextGreat(string str)
{
    int n = str.length();
    int f = 0, index;
    if (n == 1)
        return str;
    for (int i = n - 2; i >= 0; i--)
    {
        if (str[i] - '0' < str[i + 1] - '0')
        {
            index = i;
            f = 1;
            break;
        }
    }
    if (f == 0)
    {
        reverse(str.begin(), str.end());
        return str;
    }
    int j = n - 1;
    if (index >= 0)
    {
        while (str[index] - '0' > str[j] - '0')
            j--;
        swap(str[index], str[j]);
    }
    reverse(str.begin() + index + 1, str.end());
    return str;
}
int main()
{
    string str = "323242";

    /*here we will use a similar approach as we used in arrays, we will traverse from the end
    and find the first element which is smaller than its next, here above 5 is smaller than 8.

    now we need to swap our number 5 with something just bigger than it, and therefore we will again
    traverse from end and now find the first number with is bigger than it and we will swap that.
     after that we will just reverse our string after that swapped place.

    if we get a reverse string we will just return the reversed string. */

    cout << nextGreat(str);
}