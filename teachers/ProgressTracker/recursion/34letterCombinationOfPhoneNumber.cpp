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
    string number = arr[str[i] - '0'];
    for (int j = 0; j < number.size(); j++)
    {
        s.push_back(number[j]);
        fun(i + 1, str, s);
        s.pop_back();
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

// 2nd sol
vector<string> arr = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

vector<string> letterCombinations(string str)
{
    if (str.empty())
        return {};
    vector<string> ans;
    ans.push_back("");
    for (auto it : str)
    {
        vector<string> temp;
        for (auto cand : arr[it - '0'])
        {
            for (auto s : ans)
                temp.push_back(s + cand);
        }
        ans.swap(temp);
    }
    return ans;
}