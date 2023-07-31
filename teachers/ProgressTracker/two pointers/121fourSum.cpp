#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<int>> ans;
    if (n < 4)
        return ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 3; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        for (int j = i + 1; j < n - 2; j++)
        {
            if (j > i + 1 && arr[j] == arr[j - 1])
                continue;
            for (int k = j + 1, l = n - 1; k < l;)
            {
                long long sum = (long long)arr[i] + (long long)arr[j] + (long long)arr[k] + (long long)arr[l];
                if (sum == target)
                {
                    ans.push_back({arr[i], arr[j], arr[k], arr[l]});
                    int first = arr[k], second = arr[l];
                    while (k < l && arr[k] == first)
                        k++;
                    while (k < l && arr[l] == second)
                        l--;
                }
                else if (sum > target)
                    l--;
                else
                    k++;
            }
        }
    }
    return ans;
}