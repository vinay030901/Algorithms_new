#include <bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        arr[arr[i] % n] += n;
    }
    for (int i = 0; i < n; i++)
        if (arr[i] / n >= 2)
            return i;
    return 0;
}