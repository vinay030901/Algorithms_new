/*SOLUTION
the solution simply follows a sliding window appproach where we need to first find the value of first k elements in map
and then we will keep traversing the vector and decrease the value of i-kth element
and if the frequency is greater than 1, that means the element has repeated
*/
/*QUESTION
Given an unsorted array that may contain duplicates. Also given a number k which is smaller than the size of the array. Write a function that returns true if the array contains duplicates within k distance.
Examples:

Input: k = 3, arr[] = {1, 2, 3, 4, 1, 2, 3, 4}
Output: false
All duplicates are more than k distance away.

Input: k = 3, arr[] = {1, 2, 3, 1, 4, 5}
Output: true
1 is repeated at distance 3.

Input: k = 3, arr[] = {1, 2, 3, 4, 5}
Output: false

Input: k = 3, arr[] = {1, 2, 3, 4, 4}
Output: true
*/

#include <bits/stdc++.h>
using namespace std;
bool check(int arr[], int k, int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < min(k, n); i++)
    {
        mp[arr[i]]++;
        if (mp[arr[i]] > 1)
            return true;
    }
    for (int i = k; i < n; i++)
    {
        mp[arr[i]]++;
        if (mp[arr[i]] > 1)
            return true;
        mp[arr[i - k]]--;
    }
    return false;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << check(arr, k, n);
}