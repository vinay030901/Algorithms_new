/*
Given a string, find the longest substring which is palindrome.

For example,

Input: Given string :"forgeeksskeegfor",
Output: "geeksskeeg"

Input: Given string :"Geeks",
Output: "ee"*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "forgeeksskeegfor";
    int n = str.length();

    /* to find the longest substring in the string, the brute force approach could be to take all the substrings
    and check whether it is palindrome or not
    its time complexity will be O(n^3) */
    int mx = 1, start = 0;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) // nested loop to access the substring
        {
            int flag = 1;
            for (int k = 0; k < (j - i + 1) / 2; k++) // check whether it is palindrome or not
                if (str[i + k] != str[j - k])
                    flag = 0;
            if (flag && (j - i + 1) > mx) // if it is palindrome and length is more than max, we will store the
            // start and update the max value
            {
                mx = (j - i + 1);
                start = i;
            }
        }
    cout << "using brute force: ";
    for (int i = start; i < start + mx; i++)
        cout << str[i];

    // another approach could be to use dynamic programming
    bool dp[n][n];
    memset(dp, 0, sizeof(dp));
    /* here we will make a table and fill values in it on account of whether the string is palindrome or not

    for this we will the middle of table with 1, since all single character is palindrome
    then we will fill the second value of all of these, by checking if the next element is equal or not.

    now we will use our condition to check for the substrings having length greater than 2 having indices i and j
    to be palindrome-
    1. str[i] must be equal to str[j]
    2. dp[i+1][j-1] must be 1 or palindrome
    if both of these condition met, this is a palindrome

    its time complexity is O(n^2)*/

    int mxl = 1, st = 0;
    for (int i = 0; i < n; i++) // initialising all the single length elements
        dp[i][i] = 1;

    for (int i = 0; i < n - 1; i++) // initialising all the double length elements
        if (str[i] == str[i + 1])
        {
            dp[i][i + 1] = 1;
            mxl = 2;
            st = i;
        }

    for (int k = 3; k <= n; k++) // we will check for every length, first for 3, then 4, then 5
    {
        for (int i = 0; i < n - k + 1; i++) // we will now traverse the starting index of that string
        {
            int j = i + k - 1; // ending index for the given length
            if ((str[i] == str[j]) && (dp[i + 1][j - 1] == true))
            {
                dp[i][j] = true;
                mxl = k; // since are k value is increasing, we don't need comparisons and max is k only
                st = i;
            }
        }
    }
    cout << "\nmaximum palindroming substring using dp: ";
    for (int i = st; i < st + mxl; i++)
        cout << str[i];
}