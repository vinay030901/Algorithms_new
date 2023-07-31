#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0, mn = INT_MAX;
        for (int i = 0; i < prices.size(); i++)
        {
            mn = min(mn, prices[i]);
            profit = max(profit, prices[i] - mn);
        }
        return profit;
    }
};