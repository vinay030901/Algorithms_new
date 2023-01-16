#include <bits/stdc++.h>
using namespace std;
int fun(vector<int> arr, int k)
{
    int n = arr.size();
    int j = 0, i = 0, sum = 0, mx = 0;
    while (j < n)
    {
        sum += arr[j];
        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            mx = max(sum, mx);
            sum -= arr[i];
            i++;
            j++;
        }
    }
    return mx;
}
int main()
{
}