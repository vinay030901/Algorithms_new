/*
Given an array and a value, find if there is a triplet in array whose sum is equal to the given value.
If there is such a triplet present in array, then print the triplet and return true. Else return false.

Examples:


Input: array = {12, 3, 4, 1, 6, 9}, sum = 24;
Output: 12, 3, 9
Explanation: There is a triplet (12, 3 and 9) present
in the array whose sum is 24.
Input: array = {1, 2, 3, 4, 5}, sum = 9
Output: 5, 3, 1
Explanation: There is a triplet (5, 3 and 1) present
in the array whose sum is 9.*/
#include <bits/stdc++.h>
using namespace std;
bool tripleSum(int a[], int n, int sum)
{
    for (int i = 0; i < n - 2; i++)
    {
        int current_sum = sum - a[i];
        unordered_set<int> s;
        for (int j = i + 1; j < n; j++)
        {
            if (s.find(current_sum - a[j]) != s.end())
            {
                cout << a[i] << " " << a[j] << " " << current_sum - a[j] << endl;
                return true;
            }
            s.insert(a[j]);
        }
    }
    return false;
}
int main()
{
    int arr[] = {12, 3, 4, 1, 6, 9}, sum = 24;
    // the first approch is brute force one but it will take O(n^3) time which is very high
    // so we have two approaches which uses O(n^2) time, one is using sorting and other is hashing

    /*in sorting approach, we first sort the array,
    then we take a value from start
    then we use the two pointer technique to traverse the array, one index from next of taken element and other from last
    so if the sum value is smaller than the total value, we will decrease the second pointer, else
    we will increase the first pointer*/
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    cout << "using sortign: ";
    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int l = (arr[i] + arr[j] + arr[k]);
            if (l == sum)
            {
                cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                break;
            }
            else if (l < sum) // if l < sum, we need to move forward in the array
                j++;
            else
                k--;
        }
    }
    /* hashing approach contitutes of extra space
    here we traverse the array, then another traversal under this, where if check for unordered_set*/
    int a[] = {12, 3, 4, 1, 6, 9};
    n = sizeof(a) / sizeof(a[0]);
    if (tripleSum(a, n, sum))
        cout << "triple sum found";
    else
        cout << "triple sum not found";
}