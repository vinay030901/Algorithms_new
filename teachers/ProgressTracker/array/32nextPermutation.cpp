#include <bits/stdc++.h>
using namespace std;
void nextPermutation(vector<int> &arr)
{
    int n = arr.size();
    int j = n - 2;
    while (j >= 0 && arr[j] >= arr[j + 1])
        j--;
    if (j < 0)
    {
        reverse(arr.begin(), arr.end());
        return;
    }
    int ind = n - 1;
    while (arr[j] >= arr[ind])
        ind--;
    swap(arr[ind], arr[j]);
    reverse(arr.begin() + j + 1, arr.end());
}
void nextPermutation(vector<int> &arr)
{
    int n = arr.size();
    int j = n - 2;
    while (j >= 0 && arr[j] >= arr[j + 1])
        j--;
    if (j < 0)
    {
        reverse(arr.begin(), arr.end());
        return;
    }
    int ind = n - 1;
    while (arr[j] >= arr[ind])
        ind--;
    swap(arr[ind], arr[j]);
    reverse(arr.begin() + j + 1, arr.end());
}
int main()
{
}