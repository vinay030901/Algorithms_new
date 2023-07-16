/*Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up to the given integer X.


Example 1:

Input:
n = 6, X = 13
arr[] = [1 4 45 6 10 8]
Output:
1
Explanation:
The triplet {1, 4, 8} in
the array sums up to 13.
Example 2:

Input:
n = 5, X = 10
arr[] = [1 2 4 3 6]
Output:
1
Explanation:
The triplet {1, 3, 6} in
the array sums up to 10.*/
/*the solution of this question is simply we have to first sort the array so that we can use two pointers on it
then we will traverse it with i and then use two pointers for the remaining array

time complexity: O(N^2)
Space complexity: O(1)*/
#include <bits/stdc++.h>
bool find3Numbers(int arr[], int n, int x)
{
    sort(arr, arr + n);
    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum == x)
                return true;
            if (sum > x)
                k--;
            else
                j++;
        }
    }
    return false;
}
using namespace std;
int main()
{
}