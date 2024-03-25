/*Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.



Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.


Constraints:

1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.*/
#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int, char> p, pair<int, char> q)
{
    return p.first > q.first;
}
class Solution
{
public:
    string frequencySort(string s)
    {
        map<char, int> m;
        for (int i = 0; i < s.length(); i++)
        {
            m[s[i]]++;
        }
        vector<pair<int, char>> vec;
        for (auto i : m)
        {
            vec.push_back({i.second, i.first});
        }
        sort(vec.begin(), vec.end(), &compare);
        string str = "";
        for (auto i : vec)
        {
            // cout<<i.first<<' '<<i.second<<endl;
            char ch = i.second;
            while (i.first--)
                str += ch;
        }
        return str;
    }
};
int main()
{
    // Your code here
    return 0;
}