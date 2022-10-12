/*
You have been given two strings 'STR1' and 'STR2'. You have to find the length of the longest common substring.
A string “s1” is a substring of another string “s2” if “s2” contains the same characters as in “s1”, in the same order and in continuous fashion also.
For Example :
If 'STR1' = “abcjklp” and 'STR2' = “acjkp”  then the output will be 3.

Explanation: The longest common substring is “cjk” which is of length 3.
Input Format:
The first line contains an integer ‘T’ which denotes the number of test cases.

The first and only line of each test case contains two space-separated strings 'STR1' and 'STR2', respectively.
Output Format:
For each test case, return the length of the longest common substring among the two strings.

Print the output of each test case in a separate line.
Note:
You don't need to print anything, it has been already taken care of. Just implement the given function.
Constraints:
1 <= T <= 100
1 <= |STR1|, |STR2| <= 100

Where |STR1| and |STR2|  are the lengths of the string 'STR1' and 'STR2' respectively.

Time limit: 1 sec*/

#include <bits/stdc++.h>
using namespace std;
int lcs(string &str1, string &str2)
{
    int m = str1.length(), n = str2.length();
    int ans = 0;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 0;
            ans=max(ans, dp[i][j]);
        }
    }

    for (int i = 0; i <= m; i++)
    {
        for (int j =0; j <= n; j++)
        cout<<dp[i][j]<<" ";
        cout<<endl;}
    return ans;
}


int main()
{
    string s1 = "abcjklp", s2 = "acjkp";
    cout << lcs(s1, s2) << endl;
}