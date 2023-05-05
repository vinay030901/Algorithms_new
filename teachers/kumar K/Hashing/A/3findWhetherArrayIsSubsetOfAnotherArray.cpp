/*SOLUTION
the best method to solve this question is to take a map and make a frequency array of it.
then we need to traverse the second array and decrease the frequency of every element.
And if the frequency of any element goes to less than 0, then we can say that it is not subset of array
time complexity: O(m+n)
space complexity: O(m)

*/
/*QUESTION

Given two arrays: arr1[0..m-1] and arr2[0..n-1]. Find whether arr2[] is a subset of arr1[] or not. Both arrays are not in sorted order. It may be assumed that elements in both arrays are distinct.

Examples:

Input: arr1[] = {11, 1, 13, 21, 3, 7}, arr2[] = {11, 3, 7, 1}
Output: arr2[] is a subset of arr1[]

Input: arr1[] = {1, 2, 3, 4, 5, 6}, arr2[] = {1, 2, 4}
Output: arr2[] is a subset of arr1[]


Input: arr1[] = {10, 5, 2, 23, 19}, arr2[] = {19, 5, 3}
Output: arr2[] is not a subset of arr1[] */

#include <bits/stdc++.h>
using namespace std;
string isSubset(int a1[], int a2[], int n, int m)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[a1[i]]++;
    for (int i = 0; i < m; i++)
    {
        mp[a2[i]]--;
        if (mp[a2[i]] < 0)
            return "No";
    }
    return "Yes";
}
int main()
{
}