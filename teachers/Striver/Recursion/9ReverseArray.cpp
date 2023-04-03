#include <bits/stdc++.h>
using namespace std;
void reverse(int *arr, int l, int h)
{
    if (l >= h)
        return;
    else
    {
        swap(arr[l], arr[h]);
        reverse(arr, l + 1, h - 1);
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    reverse(arr, 0, n - 1);
    cout << "reversed array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}