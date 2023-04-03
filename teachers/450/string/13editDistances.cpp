/*
Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.

Insert
Remove
Replace
All of the above operations are of equal cost.

Examples:

Input:   str1 = "geek", str2 = "gesek"
Output:  1
We can convert str1 into str2 by inserting a 's'.

Input:   str1 = "cat", str2 = "cut"
Output:  1
We can convert str1 into str2 by replacing 'a' with 'u'.

Input:   str1 = "sunday", str2 = "saturday"
Output:  3
Last three and first characters are same.  We basically
need to convert "un" to "atur".  This can be done using
below three operations.
Replace 'n' with 'r', insert t, insert a*/
#include <bits/stdc++.h>
using namespace std;
int editDistance(string str1, string str2, int m, int n)
{
    if (m == 0)
        return n;
    if (n == 0)
        return m;
    if (str1[m - 1] == str2[n - 1])
        return editDistance(str1, str2, m - 1, n - 1);
    else
        return 1 + min(editDistance(str1, str2, m - 1, n), min(editDistance(str1, str2, m, n - 1),
                                                               editDistance(str1, str2, m - 1, n - 1)));
}
int main()
{
    string str1 = "gesekr", str2 = "greek";

    /*this is a dp problem, so its obvious we should think of the recursive approach here
    as we can see, here we can either insert, remove or replace the character

    let length of str1=m
    and length of str2=n.

    we will compare the values from last, so if they are 'same', we will decrease both of them-(m-1,n-1)
    and else: we will find the minimum of these three tasks in our recursive approach
    1. if we want to remove the element from str1, we will 1+(m-1,n).
    2. if we want to insert the element in str1, we will do 1+(m,n-1)
    3. if we want to replace the element in str1, we will do 1+(m-1,n-1)*/
    int m = str1.length();
    int n = str2.length();
    cout << editDistance(str1, str2, m, n);

    /*so we are getting right answer using recursion, so we will convert the recursive code into tabulat approach*/
    int dp[m + 1][n + 1] = {0};
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
        }
    cout << endl
         << dp[m][n];
}