/*Given an array of integers, find the length of the longest sub-sequence such that elements in the subsequence are
consecutive integers, the consecutive numbers can be in any order.

Examples:

Input: arr[] = {1, 9, 3, 10, 4, 20, 2}
Output: 4
Explanation:
The subsequence 1, 3, 4, 2 is the longest
subsequence of consecutive elements

Input: arr[] = {36, 41, 56, 35, 44, 33, 34, 92, 43, 32, 42}
Output: 5
Explanation:
The subsequence 36, 35, 33, 34, 32 is the longest
subsequence of consecutive elements.*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    // the naive approach could be to sort the array and then check the maximum length of subsequence
    int arr[] = {1, 9, 3, 10, 4, 20, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    int mx = 0, curr = 1;
    // since we don't want repeating numbers, we will put the numbers in vector
    vector<int> v;
    v.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
            v.push_back(arr[i]);
    }
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i - 1] + 1 == v[i])
            curr++;
        else
            curr = 1;
        mx = max(curr, mx);
    }
    cout << "using naive method: " << mx << endl;

    // another method we can use is that we can do hasing, of our array and then check if the next element is available or not.
    // find takes O(1) space and therefore it will take linear time.
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(arr[i]);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int j = 1;
        if (s.find(arr[i] - 1) == s.end())
        {
            j = arr[i];
            while (s.find(j) != s.end())
            {
                j++;
            }
            ans = max(ans, j - arr[i]);
        }
    }
    cout << "using efficeint method: " << ans << endl;
}