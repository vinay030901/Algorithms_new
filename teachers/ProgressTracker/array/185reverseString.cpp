/*Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.



Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]


Constraints:

1 <= s.length <= 105
s[i] is a printable ascii character.*/
#include <bits/stdc++.h>
using namespace std;
void reverseString(vector<char> &s)
{
    char temp;
    for (int i = 0, j = s.size() - 1; i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        // std::swap(s[i], s[j]);
    }
}
int main()
{
    // Your code here
    return 0;
}