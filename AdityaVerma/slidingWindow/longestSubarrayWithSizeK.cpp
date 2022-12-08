#include <bits/stdc++.h>
using namespace std;

// only for positive numbers
int lenOfLongSubarr(int arr[], int n, int k)
{
    // Complete the function
    int j = 0, i = 0, mx = 0, sum = 0;
    while (j < n)
    {
        sum += arr[j];
        if (sum == k)
        {
            mx = max(mx, j - i + 1);
            j++;
        }

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

int lenOfLongSubarr(int arr[], int n, int k)
{
    unordered_map<int,int>mp;
    int sum=0;
    for(int i=0; i<n; i++)
    {
        sum+=arr[i];
        mp[sum]=i;
        if(mp.find(sum-arr[i])==mp.end());
        
    }
}
int main()
{
}