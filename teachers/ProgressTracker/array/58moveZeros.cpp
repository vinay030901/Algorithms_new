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