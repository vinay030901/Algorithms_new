#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strings)
    {
        int n = strings.size();
        if (n == 0)
            return "";
        if (n == 1)
            return strings[0];
        sort(strings.begin(), strings.end());
        string str1 = strings[0], str2 = strings[n - 1];
        int s1 = str1.length(), s2 = str2.length();
        int len = min(s1, s2);
        string lcp = "";
        for (int i = 0; i < len; i++)
            if (str1[i] == str2[i])
                lcp += str1[i];
            else
                return lcp;
        return lcp;
    }
};
int main()
{
    // Your code here
    return 0;
}