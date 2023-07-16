/*SOLUTION
it has a simple solution, we need to find the maximum frequency and we will do this using map
and then we will return the difference between the length of array and the maximum frequency
TC: O(N)
SC: O(N)
*/

/*QUESTION

Given an array with n positive integers. We need to find the minimum number of operations to make all elements equal. We can perform addition, multiplication, subtraction, or division with any part on an array element.

Examples:

Input : arr[] = {1, 2, 3, 4}
Output : 3
Since all elements are different,
we need to perform at least three
operations to make them same. For
example, we can make them all 1
by doing three subtractions. Or make
them all 3 by doing three additions.

Input : arr[] = {1, 1, 1, 1}
Output : 0*/

#include <bits/stdc++.h>
using namespace std;
int minimum_operations(int arr[], int n)
{
    int maximum_frequecy = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
        maximum_frequecy = max(maximum_frequecy, mp[arr[i]]);
    }
    return n - maximum_frequecy;
}
int main()
{
    int arr[] = {1, 2, 3, 4}, n = 4;
    cout << minimum_operations(arr, n);
}