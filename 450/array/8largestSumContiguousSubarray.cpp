#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2, -1, 0, 3, 0, 4, -1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // to find the largest sum, we can make every possible permutations and then find the sum
    // this is the brute force approach and is very lengthy with O(n^2) complexity
    int mx = INT_MIN, j;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (j = i; j < n; j++)
            sum += arr[j];
        mx = max(mx, sum);
    }
    cout << "using all permutations: " << mx << endl;
    // so we have kadane algo with us which can do this task in O(n) complexity
    int currentSum = 0, max = 0;
    for (int i = 0; i < n; i++)
    {
        currentSum += arr[i];
        if (currentSum < 0)
            currentSum = 0;
        if (currentSum > max)
            max = currentSum;
    }
    cout << "using Kadane algo: " << max << endl;
}