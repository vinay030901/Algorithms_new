/*
Given two strings A and B. Find the minimum number of steps required to transform string A into string B. The only allowed operation for the transformation is selecting a character from string A and inserting it in the beginning of string A.

Example 1:

Input:
A = "abd"
B = "bad"
Output: 1
Explanation: The conversion can take place in
1 operation: Pick 'b' and place it at the front.
Example 2:

Input:
A = "GeeksForGeeks"
B = "ForGeeksGeeks"
Output: 3
Explanation: The conversion can take
place in 3 operations:
Pick 'r' and place it at the front.
A = "rGeeksFoGeeks"
Pick 'o' and place it at the front.
A = "orGeeksFGeeks"
Pick 'F' and place it at the front.
A = "ForGeeksGeeks"*/
/*
Checking whether a string can be transformed to another is simple. We need to check whether both strings have same number of characters and same set of characters. This can be easily done by creating a count array for first string and checking if second string has same count of every character.
How to find minimum number of operations when we are sure that we can transform A to B? The idea is to start matching from last characters of both strings. If last characters match, then our task reduces to n-1 characters. If last characters don’t match, then find the position of B’s mismatching character in A. The difference between two positions indicates that these many characters of A must be moved before current character of A.

Below is complete algorithm.
1) Find if A can be transformed to B or not by first creating a count array for all characters of A, then checking with B if B has same count for every character.
2) Initialize result as 0.
3) Start traversing from end of both strings.
……a) If current characters of A and B match, i.e., A[i] == B[j]
………then do i = i-1 and j = j-1
    b) If current characters don’t match, then search B[j] in remaining
………A. While searching, keep incrementing result as these characters
………must be moved ahead for A to B transformation.*/
#include <bits/stdc++.h>
using namespace std;
int transform(string A, string B)
{
    // code here.

    int n = A.length(), m = B.length();
    if (n != m)
        return -1;
    int mp[256] = {0};
    for (auto it : A)
        mp[it]++;
    for (auto it : B)
        mp[it]--;
    for (auto it : mp)
        if (it != 0)
            return -1;
    int i = n - 1, j = m - 1, res = 0;
    while (i >= 0 && j >= 0)
    {
        // If there is a mismatch, then keep incrementing
        // result 'res' until B[j] is not found in A[0..i]
        if (A[i] != B[j])
        {
            i--;
            res++;
        }
        i--;
        j--;
    }
    return res;
}