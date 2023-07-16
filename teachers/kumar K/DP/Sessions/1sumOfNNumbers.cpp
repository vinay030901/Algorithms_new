/*You are given an array and you have to find the sum of element from index 1 to given index
 */
#include <bits/stdc++.h>
using namespace std;

// but this technique is taking O(N) time and we will be given q queries, so for each query we will need to run a for loop and this
// is not efficient
void findSum(vector<int> &arr, int i)
{
    int sum = 0;
    for (int j = 0; j <= i; j++)
        sum += arr[j];
    cout << sum;
}

// we will use dp for this part
// here we will calculate the sum of elements at every point and store it
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> dp(n);
    dp[0] = arr[0];
    for (int i = 1; i < n; i++)
        dp[i] = dp[i - 1] + arr[i];
    // so the total time for optimized way is O(N*Q) time
    cout << dp[3]; // in O(1)
    return 0;
}