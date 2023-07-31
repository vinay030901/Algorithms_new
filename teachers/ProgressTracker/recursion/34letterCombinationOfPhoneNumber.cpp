#include <bits/stdc++.h>
using namespace std;
vector<string> arr = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> ans;
void fun(int i, string &str, string &s)
{
    if (i >= str.length())
    {
        ans.push_back(s);
        return;
    }
    int num = str[i] - '0';
    string number = arr[num];
    for (int j = 0; j < number.size(); j++)
    {
        fun(i + 1, str, s + number[j]);
    }

    return;
}
vector<string> letterCombinations(string str)
{
    if (str.length() == 0)
        return ans;
    string s = "";
    fun(0, str, s);
    return ans;
}