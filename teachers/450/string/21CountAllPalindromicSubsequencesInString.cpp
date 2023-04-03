/*
Find how many palindromic subsequences (need not necessarily be distinct) can be formed in a given string.
Note that the empty string is not considered as a palindrome.
Examples:

Input : str = "abcd"
Output : 4
Explanation :- palindromic  subsequence are : "a" ,"b", "c" ,"d"

Input : str = "aab"
Output : 4
Explanation :- palindromic subsequence are :"a", "a", "b", "aa"

Input : str = "aaaa"
Output : 15
*/
#include <bits/stdc++.h>
using namespace std;
int countPS(string str, int i, int j)
{

    if (i <= j)
        return 1;
    else if (str[i] == str[j])
        return 1 + countPS(str, i + 1, j) + countPS(str, i, j - 1);
    else
        return countPS(str, i + 1, j) + countPS(str, i, j - 1) - countPS(str, i + 1, j - 1);
    // https://media.geeksforgeeks.org/wp-content/uploads/20190804162927/00011.jpg

    /*case 1: when str[i]==str[j]

    (1)- we can include str[i] and str[j]-
    then we have return 1+countPS(str,i+1,j-1)
    (2)- and we can excluse both str[i] and str[j], then we are checking for other values
    return countPS(str,i+1,j)+countPS(str,i,j-1)-countPS(str,i+1,j-1)
    we are substracting it because when we do countPS(str,i+1,j) and countPS(str,i,j-1),
    then countPS(str,i+1,j-1) is taken twice, so we need to decrease it

    case 2: when str[i]!=str[j]:
    we simply check for the condition and don't take i and j together as they are not equal
    therefore we have return countPS(str,i+1,j)+countPS(str,i,j-1)-countPS(str,i+1,j-1);*/
}
int main()
{
    string str = "aab";
    int n = str.length();
    /*so this problem can be solved recursively*/
    cout << countPS(str, 0, 2);
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    for (int len = 2; len <= n; len++)
        for (int i = 0; i <= n - len; i++)
        {
            int k = len + i - 1;
            if (str[i] == str[k])
                dp[i][k] = dp[i][k - 1] + dp[i + 1][k] + 1;
            else
                dp[i][k] = dp[i][k - 1] + dp[i + 1][k] - dp[i + 1][k - 1];
        }
    cout << "\n"
         << dp[0][n - 1];
}