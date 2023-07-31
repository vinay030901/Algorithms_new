#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int> &arr)
{
    int n = arr.size(), index = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[index])
            arr[++index] = arr[i];
    }
    return index + 1;
}
int main()
{
}