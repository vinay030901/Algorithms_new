#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str1 = "yeesaa bro";
    string str2 = "malayalam";
    string s1 = str1, s2 = str2;
    // we will just reverse the string and check if previous string is equal to new string
    reverse(str1.begin(), str1.end());
    if (str1 == s1)
        cout << "string 1 is palindrome\n";
    else
        cout << "string 1 is not palindrome\n";
    reverse(str2.begin(), str2.end());
    if (str2 == s2)
        cout << "string 2 is palindrome\n";
    else
        cout << "string 2 is not palindrome\n";
}
