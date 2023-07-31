#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxArea(vector<int> &arr)
    {
        int i = 0, j = arr.size() - 1, ans = 0;
        while (i < j)
        {
            ans = max(ans, min(arr[i], arr[j]) * (j - i));
            if (arr[i] > arr[j])
                j--;
            else
                i++;
        }
        return ans;
    }
};