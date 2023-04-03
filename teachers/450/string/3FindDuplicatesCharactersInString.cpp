/*Given a string str, the task is to find all the duplicate characters present in a given string in lexicographical order without using any additional data structure.

Examples:

Input: str = “geeksforgeeks”
Output: e g k s
Explanation:
Frequency of character ‘g’ = 2
Frequency of character ‘e’ = 4
Frequency of character ‘k’ = 2
Frequency of character ‘s’ = 2
Therefore, the required output is e g k s.

Input: str = “apple”
Output: p
Explanation:
Frequency of character ‘p’ = 2.
Therefore, the required output is p.*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "hello brother";
    // to find the duplicate characters, we can use map
    // traverse using map and check the count of every character, then print which have more than 1 count
    map<char, int> mp;
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        mp[str[i]]++;
        if (mp[str[i]] == 2) // if the character appeared twice, we can just print it
            cout << str[i] << " ";
    }

    // to do this without using extra space, we can just sort the string, same elements appear together
    // and we can print it
    cout << "\nusing sorting: ";
    sort(str.begin(), str.end());
    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            cout << str[i] << " ";
            while (str[i] == str[i + 1])
                ++i;
        }
    }
}