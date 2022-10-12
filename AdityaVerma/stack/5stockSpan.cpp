/*
The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to
calculate the span of the stock’s price for all n days. The span Si of the stock’s price on a given day i is defined as
the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is
less than its price on the given day.
Example:

Input: N = 7, price[] = [100 80 60 70 60 75 85]
Output: 1 1 1 2 1 4 6
Explanation: Traversing the given input span for 100 will be 1, 80 is smaller than 100 so the span is 1, 60 is smaller than 80
so the span is 1, 70 is greater than 60 so the span is 2 and so on. Hence the output will be 1 1 1 2 1 4 6.
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> stockSpan(vector<int> &arr)
{
    int n = arr.size();
    stack<pair<int, int>> s;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (s.empty())
            ans.push_back(1);
        else if (s.top().first > arr[i])
            ans.push_back(i - s.top().second);
        else
        {
            while (!s.empty() && s.top().first <= arr[i])
                s.pop();
            if (s.empty())
                ans.push_back(i + 1);
            else
                ans.push_back(i - s.top().second);
        }
        s.push({arr[i], i});
    }
    return ans;
}
int main()
{
    vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans = stockSpan(arr);
    for (auto it : ans)
        cout << it << " ";
}