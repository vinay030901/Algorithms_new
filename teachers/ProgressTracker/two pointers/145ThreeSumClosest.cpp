#include <bits/stdc++.h>
using namespace std;
int threeSumClosest(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    int sum = arr[0] + arr[1] + arr[2];
    for (int i = 0; i < arr.size() - 2; i++)
    {
        int j = i + 1, k = arr.size() - 1;
        while (j < k)
        {
            int s = arr[i] + arr[j] + arr[k];
            if (abs(target - sum) > abs(target - s))
            {
                sum = s;
            }
            if (s > target)
                k--;
            else
                j++;
        }
    }
    return sum;
}