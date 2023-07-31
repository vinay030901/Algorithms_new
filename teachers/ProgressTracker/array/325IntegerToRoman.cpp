#include <bits/stdc++.h>
using namespace std;
string intToRoman(int num)
{
    vector<pair<int, string>> val = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
    string str = "";
    for (int i = 0; i < val.size(); i++)
    {
        if (num / val[i].first >= 1)
        {
            int n = num / val[i].first;
            while (n--)
            {
                str += val[i].second;
            }
        }
        num = num % val[i].first;
    }
    return str;
}