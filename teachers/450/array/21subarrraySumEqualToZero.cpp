#include <bits/stdc++.h>
using namespace std;
bool check(int arr[], int n)
{
    unordered_set<int> s; // we will use unordered_set to check if any sum is available or not in O(1) time.
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0) // check if any element is 0
            return true;
        sum += arr[i]; // finding the sum of elements
        if (sum == 0)
            return true;
        if (s.find(sum) != s.end()) // finding if we have sum value available in set
            return true;
        s.insert(sum); // if we doesn't find that value we will insert the value in unordered_set
    }
    return false; // if we doesn't find the 0 sum subarray, then we will return false
}
int main()
{
    int arr[] = {4, 2, 3, 1, 6};

    // we can easily do the O(n^2) approach for solving this question
    // just traverse the array and use nested loop, check if the sum of that subarray is equal to zero
    int n = sizeof(arr) / sizeof(arr[0]);
    // we will use hashing approach for this question, we will sum over the whole array and if the sum repeats, then we will say
    // that we have an subarray having sum equal to zero
    cout << check(arr, n);
}