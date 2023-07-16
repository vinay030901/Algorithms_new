/*
You are given an array of strings words. Each element of words consists of two lowercase English letters.
Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.
Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.
A palindrome is a string that reads the same forward and backward.
Example 1:

Input: words = ["lc","cl","gg"]
Output: 6
Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
Note that "clgglc" is another longest palindrome that can be created.
Example 2:

Input: words = ["ab","ty","yt","lc","cl","ab"]
Output: 8
Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
Note that "lcyttycl" is another longest palindrome that can be created.
Example 3:

Input: words = ["cc","ll","xx"]
Output: 2
Explanation: One longest palindrome is "cc", of length 2.
Note that "ll" is another longest palindrome that can be created, and so is "xx".*/
/*
Explanation:

2 letter words can be of 2 types:

Where both letters are same
Where both letters are different
Based on the above information:

If we are able to find the mirror of a word, ans += 4
The variable unpaired is used to store the number of unpaired words with both letters same.
Unpaired here means a word that has not found its mirror word.
At the end if unpaired same letter words are > 0, we can use one of them as the center of the palindromic string.*/
#include <bits/stdc++.h>
using namespace std;
int longestPalindrome(vector<string> &words)
{
    int count[26][26] = {0};
    int ans = 0;
    for (auto it : words)
    {
        int a = it[0] - 'a', b = it[1] - 'a';
        if (count[b][a]) // if we get dl, then we check if get ld
        {
            ans += 4;
            count[b][a]--;
        }
        else
            count[a][b]++;
    }
    for (int i = 0; i < 26; i++)
        if (count[i][i]) // we can check if have some dd type of element, we will add only two because otherwise it would have
        // decreased, so reamaining could be only 1
        {
            ans += 2;
            break;
        }
    return ans;
}
int main()
{

    return 0;
}