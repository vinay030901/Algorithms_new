#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &arr)
    {
        vector<vector<int>> ans;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && arr[i] == arr[i - 1])
                continue;
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum == 0)
                {
                    ans.push_back({arr[i], arr[j], arr[k]});
                    int left = arr[j], right = arr[k];
                    while (j < k && arr[j] == left)
                        j++;
                    while (j < k && arr[k] == right)
                        k--;
                }
                else if (sum < 0)
                    j++;
                else
                    k--;
            }
        }
        return ans;
    }
};