#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0, j = n - 1; i < n / 2; i++, j--)
    {
        swap(arr[i], arr[j]);
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}