#include <bits/stdc++.h>
using namespace std;
int countPairs(vector<int> &arr, int x)
{
    sort(arr.begin(), arr.end());
    int i = 0, j = arr.size() - 1, ans = 0;
    while (i < j)
    {
        if (arr[i] + arr[j] > x)
        {
            ans += (arr.size() - j);
            i++;
        }
        else
            j--;
    }
    return ans;
}