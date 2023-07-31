#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> &arr)
{
    int cnt = 1, mx = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] == mx)
            cnt++;
        else
            cnt--;
        if (cnt == 0)
        {
            mx = arr[i];
            cnt = 1;
        }
    }
    return mx;
}