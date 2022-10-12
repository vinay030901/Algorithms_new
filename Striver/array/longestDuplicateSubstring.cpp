#include <bits/stdc++.h>
using namespace std;
/*
we will calculate all the possible substrings and check if it has repeated substring
one important part is the if we have a duplicate of on certain length, then we can get a duplicate substring on length+1
but if we don't have any duplicate substring on that length, we can't have duplicate length forward, so that we will be our answer
we can therefore use binary search here
string- banana
l   1   2   3   4       5
0   b   ba  ban bana    banan
0   a   an  ana anan    anana
0   n   na  nan nana
0   a   an  ana 4 lenth doesn't have any answer
0   n   na
0   a
*/
int prime = 10000001;

vector<int> power;

string rabin_karp(string str, int len)
{
    if (len == 0)
        return "";
    int n = str.length(), curr = 0;
    unordered_map<long, vector<int>> hash;
    for (int i = 0; i < len; i++)
    {
        curr = (curr * 26 + (str[i] - 'a')) % prime;
    }
    hash[curr] = {0};
    for (int i = len; i < n; i++)
    {
        curr = ((curr - power[len - 1] * (str[i - len] - 'a')) % prime + prime) % prime;
    }
}
string longestDuplicateString(string str)
{
    int n = str.length();
    int l = 0, r = n - 1;
    power = vector<int>(n);
    power[0] = 1;
    for (int i = 1; i < n; i++)
        power[i] = (power[i - 1] * 26) % prime;
    string res;
    while (l <= r)
    {
        int mid = (l + (r - l)) / 2;
        string curr = rabin_karp(str, mid);
        if (curr.length() > res.length())
        {
            res = curr;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return res;
}
int main()
{
}