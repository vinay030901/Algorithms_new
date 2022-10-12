/*
Given heights of n towers and a value k. We need to either increase or decrease the height of every tower by k (only once) 
where k > 0. The task is to minimize the difference between the heights of the longest and the shortest tower after 
modifications and output this difference.
Examples:

Input  : arr[] = {1, 15, 10}, k = 6
Output :  Maximum difference is 5.
Explanation : We change 1 to 7, 15 to
9 and 10 to 4. Maximum difference is 5
(between 4 and 9). We can't get a lower
difference.

Input : arr[] = {1, 5, 15, 10}
        k = 3
Output : Maximum difference is 8
arr[] = {4, 8, 12, 7}

Input : arr[] = {4, 6}
        k = 10
Output : Maximum difference is 2
arr[] = {14, 16} OR {-6, -4}

Input : arr[] = {6, 10}
        k = 3
Output : Maximum difference is 2
arr[] = {9, 7}

Input : arr[] = {1, 10, 14, 14, 14, 15}
        k = 6
Output: Maximum difference is 5
arr[] = {7, 4, 8, 8, 8, 9}

Input : arr[] = {1, 2, 3}
        k = 2
Output: Maximum difference is 2
arr[] = {3, 4, 5}
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
        int arr[] = {1, 5, 15, 10};
        int k = 6;
        int n = sizeof(arr) / sizeof(arr[0]);
        // the brute force algorithm could be to check by incrementing and decrementing every number, that is we have
        // to check all the permutations

        // this is an easy approach for this task, we will sort the array and check after adding and subtracting from adjacent values
        // if they are getting lower or extending from smallest and largest value, if they are just we are just changing the value of
        // mx and min
        sort(arr, arr + n);
        int mn, mx;
        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;
        int ans = largest - smallest;
        for (int i = 0; i < n - 1; i++)
        {
                mn = min(smallest, arr[i + 1] - k); // check if gets lower after minimizing it
                mx = max(largest, arr[i] + k);
                if (mn < 0) // if mn is lower than 0, we will continue as it will just increase the value of ans
                        continue;
                ans = min(ans, mx - mn);
        }
        cout << ans;
}