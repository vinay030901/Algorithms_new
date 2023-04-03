/*
Given an array of n integers where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets such that:

Each student gets one packet.
The difference between the number of chocolates in the packet with maximum chocolates and packet with minimum chocolates given to the students is minimum.
Examples:

Input : arr[] = {7, 3, 2, 4, 9, 12, 56} , m = 3
Output: Minimum Difference is 2
Explanation:
We have seven packets of chocolates and
we need to pick three packets for 3 students
If we pick 2, 3 and 4, we get the minimum
difference between maximum and minimum packet
sizes.

Input : arr[] = {3, 4, 1, 9, 56, 7, 9, 12} , m = 5
Output: Minimum Difference is 6
Explanation:
The set goes like 3,4,7,9,9 and the output
is 9-3 = 6

Input : arr[] = {12, 4, 7, 9, 2, 23, 25, 41,
30, 40, 28, 42, 30, 44, 48,
43, 50} , m = 7
Output: Minimum Difference is 10
Explanation:
We need to pick 7 packets. We pick 40, 41,
42, 44, 48, 43 and 50 to minimize difference
between maximum and minimum.
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50}, m = 7;
    int n = sizeof(arr) / sizeof(arr[0]);

    // the first method we could do is sorting all the numbers.
    // then we can easily find elements with least difference between them
    sort(arr, arr + n);
    int mn = INT_MAX;
    for (int i = 0; i < n - m + 1; i++)
    {
        if (mn > (arr[i + m - 1] - arr[i]))
            mn = arr[i + m - 1] - arr[i];
    }
    cout << "using sorting: " << mn;
}