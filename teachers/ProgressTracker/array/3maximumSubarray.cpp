#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &arr)
    {
        int sum = 0, mx = INT_MIN;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            mx = max(sum, mx);
            if (sum < 0)
                sum = 0;
        }
        return mx;
    }
};