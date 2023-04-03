#include <iostream>
#include <math.h>
using namespace std;
int interpolationSearch(int arr[], int x, int n)
{
    int l = 0, h = n - 1;
    while (l <= h && arr[l] <= x && arr[h] >= x)
    {
        if (l == h)
        {
            if (arr[l] == x)
            {
                return l;
            }
            return -1;
        }
        int pos = l + (((double)(h - l) / (arr[h] - arr[l])) * (x - arr[l]));
        if (arr[pos] == x)
            return pos;
        if (arr[pos] < x)
            l = pos + 1;
        else
            h = pos - 1;
    }
    return -1;
}
int main()
{
    int arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21,
                 34, 55, 89, 144, 233, 377, 610};
    int x = 55;
    int n = sizeof(arr) / sizeof(arr[0]);

    // Find the index of 'x' using Jump Search
    int index = interpolationSearch(arr, x, n);

    // Print the index where 'x' is located
    cout << "\nNumber " << x << " is at index " << index;
    return 0;
}