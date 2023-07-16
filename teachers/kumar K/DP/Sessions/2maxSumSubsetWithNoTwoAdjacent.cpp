/*we are given an array and we need to find the maximum sum of subset where no two elements are adjacent to each other

for exam: we have {1,2,3,4,5,6} then we can not include 4 and 5 because they are not adjacent
and then we have to choose the subset with maximum*/
#include <bits/stdc++.h>
using namespace std;
int findMax(vector<int> arr, int n)
{
    // we need to find the best answer of the questions till a particular size
    // if size is 1, then first element is our answer,if size is 2, then max of them is our answer
    // if size is 3, then we can take either 2nd element or 1st and 3rd element sum of them'
    // our answer becomes dp[i]=max(dp[i-1],arr[i]+dp[i-2])
    vector<int> dp(n, 0);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
    }
    return dp[n - 1];
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << findMax(arr, n) << endl;
    return 0;
}