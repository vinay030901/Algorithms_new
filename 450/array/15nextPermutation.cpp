#include <bits/stdc++.h>
using namespace std;
void reverser(vector<int> &arr, int i, int j)
{
    while (i < j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}
void nextPermutation(int n, vector<int> &arr)
{
    if (n <= 1)
        return;
    int flag = 0;
    int index = INT_MAX;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            index = i;
            flag = 1;
            break;
        }
    }
    int j = n - 1;
    if (flag == 0)
    {
        reverse(arr.begin(), arr.end());
        return;
    }
    if (index >= 0)
    {
        while (arr[index] > arr[j])
            j--;
        swap(arr[index], arr[j]);
    }
    reverser(arr, index + 1, n - 1);
    return;
}
int main()
{
    vector<int> arr = {2, 5, 8, 7, 6, 4};
    int n = 6;
    nextPermutation(n, arr);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}