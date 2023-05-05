/*
to solve this question, we will traverse the array and keep storing the sum till ith position in sum variable and in map
then we will check if there is an instance where we have value sum-k, because it means we have got to this particular sum
at this position, and we will add the number of times it happened into our answer2*/
/*Given an unsorted array of integers, find the number of subarrays having a sum exactly equal to a given number k.

Examples:

Input : arr[] = {10, 2, -2, -20, 10}, k = -10
Output : 3
Explanation: Subarrays: arr[0…3], arr[1…4], arr[3..4] have a sum exactly equal to -10.

Input : arr[] = {9, 4, 20, 3, 10, 5}, k = 33
Output : 2
Explanation: Subarrays : arr[0…2], arr[2…4] have a sum exactly equal to 33.*/

#include <bits/stdc++.h>
using namespace std;
int findSubArraySum(int arr[], int n, int k)
{
    unordered_map<int, int> mp;
    int sum = 0, ans = 0;
    mp[sum] = 1;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (mp.find(sum - k) != mp.end())
            ans += mp[sum - k];
        mp[sum]++;
    }

    return ans;
}
int main()
{
}