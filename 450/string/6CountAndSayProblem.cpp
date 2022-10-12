/*
he count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a
different digit string.
To determine how you "say" a digit string, split it into the minimal number of groups so that each group is a
contiguous section all of the same character. Then for each group, say the number of characters, then say the character. To convert the saying into a digit string, replace the counts with a number and concatenate every saying.

For example, the saying and conversion for digit string "3322251":


Given a positive integer n, return the nth term of the count-and-say sequence.



Example 1:

Input: n = 1
Output: "1"
Explanation: This is the base case.
Example 2:

Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 4;
    string str = "";
    // here we will use an O(n) approach, we know if n is 1, answer is 1, if n is 2, answer is "11"
    // else we will compute answer using this
    if (n == 1)
        cout << "1";
    else if (n == 2)
        cout << "11";
    else
    {
        string str = "11";
        for (int i = 3; i <= n; i++)
        {
            str += "&"; // here we will add any symbol so we can get extra element for our loop
            int c = 1;
            string ans = ""; // string will be saved in this
            for (int j = 1; j < str.length(); j++)
            {
                if (str[j] == str[j - 1]) // so if this str[j] is equal to previous one, we will increment c, otherwise
                    // c will go in ans with the previous string
                    c++;
                else
                {
                    ans = ans + to_string(c) + str[j - 1]; // ans goes in the string
                    c = 1;                                 // when we put that string in answer, c becomes one
                }
            }
            str = ans;
        }
        cout << str; // we will print the answer at the end
    }
}