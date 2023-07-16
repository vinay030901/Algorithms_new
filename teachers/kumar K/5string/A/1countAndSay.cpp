#include <bits/stdc++.h>
using namespace std;
string countAndSay(int n)
{
    if (n == 1)
        return "1";
    if (n == 2)
        return "11";
    string str = "11";
    for (int i = 3; i <= n; i++)
    {
        str += "&";
        string t = "";
        int c = 1;
        for (int j = 1; j < str.length(); j++)
        {
            if (str[j] == str[j - 1])
                c++;
            else
            {
                t += {to_string(c) + str[j - 1]};
                c = 1;
            }
        }
        str = t;
    }
    return str;
}