#include <bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int> &arr)
{
    int j = 0;
    for (int i = 0; i < arr.size(); i++)
        if (arr[i])
            arr[j++] = arr[i];
    for (; j < arr.size(); j++)
        arr[j] = 0;
}
void moveZeroes(vector<int> &arr)
{
    int i = 0, j = 0, n = arr.size();
    while (i < n && j < n)
    {
        while (i < n && arr[i] != 0)
            i++;
        j = i + 1;
        while (j < n && arr[j] == 0)
            j++;
        if (i < n && j < n)
        {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
    }
}