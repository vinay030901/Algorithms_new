#include <bits/stdc++.h>
using namespace std;
int minimumKeypad(string text)
{
    unordered_map<char, int> mp;
    int total_char = 0;
    int ans = 0;
    for (int i = 0; i < text.size(); i++)
    {
        if (mp.find(text[i]) != mp.end())
            ans += mp[text[i]];
        else
        {
            total_char++;
            if (total_char < 10)
            {
                mp[text[i]] = 1;
                ans += 1;
            }            else if (total_char < 19)
            {
                mp[text[i]] = 2;
                ans += 2;
            }
            else
            {
                mp[text[i]] = 3;
                ans += 3;
            }
        }
    }
    return ans;
}
int main()
{
    cout << minimumKeypad("abacadefghibj");
}