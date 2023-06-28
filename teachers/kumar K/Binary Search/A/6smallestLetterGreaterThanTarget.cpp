/*
You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.

Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.
Example 1:

Input: letters = ["c","f","j"], target = "a"
Output: "c"
Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.
Example 2:

Input: letters = ["c","f","j"], target = "c"
Output: "f"
Explanation: The smallest character that is lexicographically greater than 'c' in letters is 'f'.
Example 3:

Input: letters = ["x","x","y","y"], target = "z"
Output: "x"
Explanation: There are no characters in letters that is lexicographically greater than 'z' so we return letters[0].*/
#include <bits/stdc++.h>
using namespace std;
char nextGreatestLetter(vector<char> &arr, char target)
{
    int l = 0, h = arr.size() - 1;
    char ans = arr[0];
    while (l < h)
    {
        int mid = l + (h - l) / 2;
        if (arr[mid] > target)
        {
            h = mid;
        }
        else
            l = mid + 1;
    }
    return arr[h] > target ? arr[h] : arr[0];
}
int main()
{

    return 0;
}