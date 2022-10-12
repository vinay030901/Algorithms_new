/*
Given a binary string str of length N, the task is to find the maximum count of consecutive substrings str can be divided into such that all the substrings are balanced i.e. they have equal number of 0s and 1s. If it is not possible to split str satisfying the conditions then print -1.
Example:


Input: str = “0100110101”
Output: 4
The required substrings are “01”, “0011”, “01” and “01”.
Input: str = “0111100010”
Output: 3

Input: str = “0000000000”

Output: -1*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "0100110101", s = "";
    int n = str.length();
    /* we used a simple approach here, we took a variable for count of zero and another for count of 1
    increment whenenver either 0 occur or 1

    if both of them are equal at any point, we will increment the count*/
    int cntz = 0, cnto = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '0')
            cntz++;
        else
            cnto++;
        if (cntz == cnto)
            cnt++;
    }
    cout << cnt;
}