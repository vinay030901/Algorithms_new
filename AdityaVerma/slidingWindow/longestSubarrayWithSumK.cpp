#include <bits/stdc++.h>
using namespace std;
int fun(vector<int> &arr, int k, int n)
{
    int j = 0, i = 0, mx = 0, sum = 0;
    while (j < n)
    {
        sum += arr[j];
        if (sum == k)
            mx = max(mx, j - i + 1);
        else if (sum < k)
            j++;
        else
        {
            while (sum > k)
            {
                sum -= arr[i];
                i++;
            }
            if (sum == k)
                mx = max(mx, j - i + 1);
            j++;
        }
    }
    return mx;
}
int main()
{
}