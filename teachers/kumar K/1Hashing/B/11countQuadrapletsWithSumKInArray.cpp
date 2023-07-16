/*
Given an array arr[] of size N and an integer S, the task is to find the count of quadruplets present in the given array having sum S.

Examples:

Input: arr[] = {1, 5, 3, 1, 2, 10}, S = 20
Output: 1
Explanation: Only quadruplet satisfying the conditions is arr[1] + arr[2] + arr[4] + arr[5] = 5 + 3 + 2 + 10 = 20.

Input: N = 6, S = 13, arr[] = {4, 5, 3, 1, 2, 4}
Output: 3
Explanation: Three quadruplets with sum 13 are:


arr[0] + arr[2] + arr[4] + arr[5] = 4 + 3 + 2 + 4 = 13
arr[0] + arr[1] + arr[2] + arr[3] = 4 + 5 + 3 + 1 = 13
arr[1] + arr[2] + arr[3] + arr[5] = 5 + 3 + 1 + 4 = 13
*/
/*Efficient Approach: The idea is similar to the above approach using a map. In this approach, fix the 3rd element, then find and store the frequency of sums of all possible first two elements of any quadruplet of the given array. Follow the below steps to solve the problem:

Initialize the counter count to store the total quadruplets with the given sum S and a map to store all possible sums for the first two elements of each possible quadruplet.
Traverse the given array over the range [0, N – 1] using the variable i where arr[i] is the fixed 3rd element.
Then for each element arr[i] in the above step, traverse the given array over the range [i + 1, N – 1] using the variable j and increment the counter count by map[arr[i] + arr[j]].
After traversing from the above loop, for each element arr[i], traverse the array arr[] from j = 0 to i – 1 and increment the frequency of any sum arr[i] + arr[j] of the first two elements of any possible quadruplet by 1 i.e., increment map[arr[i] + arr[j]] by 1.
Repeat the above steps for each element arr[i] and then print the counter count as the total number of quadruplets with the given sum S.

the main idea in this code is that we need to find the k-sum */
#include <bits/stdc++.h>
using namespace std;
int findQuadraplets(vector<int> &arr, int n, int k)
{
    unordered_map<int, int> mp;
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = arr[i] + arr[j];
            if (sum < k)
                count += mp[k - sum];
        }
        for (int j = 0; j < i; j++)
        {
            int sum = arr[i] + arr[j];
            if (sum < k)
                mp[sum]++;
        }
    }
    return count;
}
int main()
{
}