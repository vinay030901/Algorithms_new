#include <bits/stdc++.h>
using namespace std;
// https://geuac-my.sharepoint.com/personal/vinaykumar_19021019_cst_geu_ac_in/_layouts/OneNote.aspx?id=%2Fpersonal%2Fvinaykumar_19021019_cst_geu_ac_in%2FDocuments%2FVinay%20%40%20Graphic%20Era%20University
int fun(string &s, int i, string &p, int j, vector<vector<int>> &dp)
{
    // the logic here is, we ae using recursion
    // so, at the start, we will compare whether the values are equal or the pattern has ? in it, if one of the contion is correct,
    // then we can say that pattern matches in that part and therefore we will move on
    // in the next condition we have *, so if have * we will use a simple recursion statement, which is that we will either take the
    // the string or not take the string
    // so in one case, we will decrease the value of j(pattern), that is we didn't consider the * here, or we will stop considering 
    // the * from here
    // or else we will decrease the value of i(stirng), means that we took the value at i into the consideration of the pattern
    // in this way, all the part will be matched
    // if it is not *, then we return false

    // talking about the base condition
    // 1. both the value of i and j becomes -1, in this case we return true
    // 2. the string still has values but the values in pattern are exhausted, in this vcase we return false
    // 3. the string is exhausted, but the pattern is not, so in this , there is only one condition where we can have true as the answer
    // when all the values remaining are *, so we will check for this condition
    if (i < 0 && j < 0)
        return true; 
    else if (j < 0 && i >= 0)
        return false;
    else if (j >= 0 && i < 0)
    {
        for (int k = 0; k <= j; k++)
            if (p[k] != '*')
                return false;
        return true;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i] == p[j] || p[j] == '?')
        return dp[i][j] = fun(s, i - 1, p, j - 1, dp);
    if (p[j] == '*')
    {
        return dp[i][j] = fun(s, i - 1, p, j, dp) || fun(s, i, p, j - 1, dp);
    }
    return dp[i][j] = false;
}
bool isMatch(string s, string p)
{

    int n = s.length(), m = p.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return fun(s, n - 1, p, m - 1, dp);
}
int main()
{
}