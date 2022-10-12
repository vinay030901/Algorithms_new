/*
Given a string s1 and a string s2, write a snippet to say whether s2 is a rotation of s1?
(eg given s1 = ABCD and s2 = CDAB, return true, given s1 = ABCD, and s2 = ACBD , return false)

Algorithm: areRotations(str1, str2)

    1. Create a temp string and store concatenation of str1 to
       str1 in temp.
                          temp = str1.str1
    2. If str2 is a substring of temp then str1 and str2 are
       rotations of each other.

    Example:
                     str1 = "ABACD"
                     str2 = "CDABA"

     temp = str1.str1 = "ABACDABACD"
     Since str2 is a substring of temp, str1 and str2 are
     rotations of each other.*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str1 = "ABACD", str2 = "CDABA";
    // we will add str1 to str1, this will give us the concantenated string
    // then we will search str2 in it
    string new_str = str1 + str1;
    if (new_str.find(str2) != string::npos)
        cout << "string 2 is rotation of string 1";
    else
        cout << "string 2 is not rotation of string 2";
}