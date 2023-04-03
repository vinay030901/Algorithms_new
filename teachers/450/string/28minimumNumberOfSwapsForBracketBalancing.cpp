/*
You are given a string of 2N characters consisting of N ‘[‘ brackets and N ‘]’ brackets. A string is considered balanced
if it can be represented in the for S2[S1] where S1 and S2 are balanced strings. We can make an unbalanced string balanced
by swapping adjacent characters. Calculate the minimum number of swaps necessary to make a string balanced.

Examples:

Input  : []][][
Output : 2
First swap: Position 3 and 4
[][]][
Second swap: Position 5 and 6
[][][]

Input  : [[][]]
Output : 0
[[][[
The string is already balanced.*/
#include <bits/stdc++.h>
using namespace std;
int count(string str, int n)
{
    int ans = 0, c = 0;

    for (int i = 0; i < n; i++)
    {
        if (str[i] == '[') // we will count the number of opening brackets here and decrease at the time of closing brackets
            c++;
        else
        {
            c--;
            if (c < 0)
            // if the count decrease than 0, it means we have encounterd more closing brackets than opening one, so we will increase 
            // the answer, which is the number of swaps we will do
                ans -= c;
        }
    }
    return ans += c;
}

// minimum number of swaps to make string balanced
int minSwaps(string str) {
    stack<int>s;
    int n=str.length();
    for(int i=0;i<n;i++)
    {
        if(!s.empty() && str[i]==']') s.pop();
        else s.push(str[i]);
    }
    return (s.size()+1)/2;
}
int main()
{
    string str = "[]][][";

    // here we need to count the swaps we need to do in adjacent places
    int n = str.length();
    cout << count(str, n);
}