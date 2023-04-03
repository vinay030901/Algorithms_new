/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // this question could be solved in O(n) time using dp
    // the approach requires calculating profit from both sides
    // that is, using multiple traversals
    // in first traversal, we will move from right to left, we will use a dp array for this process
    // while doing it, we will calculate maximum profit, by subtracting the array value from max value in till then
    // in that array
    int arr[] = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int mx = arr[n - 1]; // max value from end
    vector<int> dp(n, 0);
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > mx)
            mx = arr[i];
        dp[i] = max(dp[i + 1], mx - arr[i]); // so this will create out dp array, where max profits are stored
        // till every index
    }
    // now we will find max profit from starting
    int mn = arr[0]; // mn is the least value for now
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < mn)
            mn = arr[i];
        dp[i] = max(dp[i - 1], dp[i] + (arr[i] - mn));
    }
    cout << "maximum profit stock using dp: " << dp[n - 1] << endl;

    // another approach use linear time and contant Space
    // In this approach we have 4 variables, buy1,buy2,profit1,profit2
    // what we do is, first we buy any stock under buy1 and calculate the profit.
    // so now, when we buy the second stock under buy2, we use the money made in first profit
    // and then calculate profit2 using that
    // for example we have arr[]={3,5,4,5}
    // we buy stock=3, buy1=3, then we sell it on next day, profit=(5-3)=2
    // now we will buy stock=4, but buy2 will be (4-buy1)=(4-2)=2
    // now the profit2 on next day=(5-buy2)=(5-2)=3-> and 3 is our answer

    int buy1, buy2, profit1, profit2;
    buy1 = buy2 = INT_MAX;
    profit1 = profit2 = 0;
    for (int i = 0; i < n; i++)
    {
        buy1 = min(buy1, arr[i]);              // buying at a low price
        profit1 = max(profit1, arr[i] - buy1); // making higher profit
        buy2 = min(buy2, arr[i] - profit1);    // buying the stock by using the profit
        profit2 = max(profit2, arr[i] - buy2); // now calculating the total profit by decreasing the buy2, which also constitutes buy1
    }
    cout << "maximum profit stock using linear approach: " << profit2 << endl;
}