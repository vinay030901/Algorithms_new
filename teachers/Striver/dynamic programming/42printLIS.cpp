#include <bits/stdc++.h>
using namespace std;
int lengthOfLIS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> lis(n, 1), hash(n, -1);
    int mx = 1, last_index = 0;
    for (int i = 1; i < n; i++)
    {
        hash[i] = i;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[j] + 1 > lis[i])
            {
                lis[i] = lis[j] + 1;
                mx = max(mx, lis[i]);
                hash[i] = j;
            }
        if (lis[i] > mx)
        {
            mx = lis[i];
            last_index = i;
        }
    }

    vector<int> temp;
    temp.push_back(arr[last_index]);
    while (hash[last_index] != last_index)
    {
        last_index = hash[last_index];
        temp.push_back(arr[last_index]);
    }
    reverse(temp.begin(), temp.end());
    for (auto it : temp)
        cout << it << " ";
    return mx;
}
int main()
{
}