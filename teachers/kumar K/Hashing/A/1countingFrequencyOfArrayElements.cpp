/*SOLUTION METHOD
we can simply use unordered_map to solve this questions
the time complexity is linear and we also have linear space complexity
*/

/* QUESTIONS

Given an array which may contain duplicates, print all elements and their frequencies.

Examples:

Input :  arr[] = {10, 20, 20, 10, 10, 20, 5, 20}
Output : 10 3
         20 4
         5  1

Input : arr[] = {10, 20, 20}
Output : 10 1
         20 2 */

#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {10, 20, 20, 10, 10, 20, 5, 20};
    unordered_map<int, int> mp;
    for (auto &it : arr)
        mp[it]++;
    for (auto it : mp)
        cout << it.first << " " << it.second << endl;
}