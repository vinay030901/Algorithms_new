#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>> &arr)
{
    int index = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[index][1] >= arr[i][0])
            arr[index][1] = max(arr[index][1], arr[i][1]);
        else
            arr[++index] = arr[i];
    }
    arr.resize(index + 1);
    return arr;
}