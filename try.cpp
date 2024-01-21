#include <bits/stdc++.h>
using namespace std;
void decodeSequence(string str)
{
    unordered_map<string, string> mp;
    mp["001"] = "C";
    mp["010"] = "G";
    mp["011"] = "A";
    mp["101"] = "T";
    mp["110"] = "U";
    bool dna = false;
    if (str[0] == '0')
        dna = true;
    string ans = "";
    for (int i = 3; i <= str.length(); i += 3)
    {
        string s = str.substr(i, 3);
        if (mp[s] == "T" || mp[s] == "U")
        {
            if (dna)
                ans += "T";
            else
                ans += "U";
        }
        else
            ans += mp[s];
    }
    cout << ans;
}
int main()
{
    string str;
    cin >> str;
    decodeSequence(str);
}