/*SOLUTION

since the array is not sorted, we can't use two pointers
therefore we have to use hashing for solving this question
Our approach will be to traverse the array and keep storing the elements and then check if (x-arr[i]) is present in the map
*/
/*QUESTION

Given an array A[] of n numbers and another number x, the task is to check whether or not there exist two elements in A[] whose sum is exactly x.

Examples:

Input: arr[] = {0, -1, 2, -3, 1}, x= -2
Output: Yes
Explanation:  If we calculate the sum of the output,1 + (-3) = -2
Input: arr[] = {1, -2, 1, 0, 5}, x = 0
Output: No*/

#include <bits/stdc++.h>
using namespace std;
bool hasArrayTwoCandidates(int arr[], int n, int x)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(x - arr[i]) != mp.end())
            return true;
        mp[arr[i]] = 1;
    }
    return false;
}
int main()
{
}