#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {4, 5, -2, 4, -4, -5, -6, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    // this could be easily done by sorting but we won't do it due to NlogN complexity,
    // we can do it in linear complexity
    int neg = 0, pos = 0;
    while (pos < n)
    {
        if (arr[pos] >= 0)
        {
            // if a positive number comes, we'll just move on from there, so that we could swap it when we get negative
            pos++;
        }
        else if (arr[pos] < 0)
        {
            // here we found negative element, so we'll swap it
            swap(arr[neg++], arr[pos++]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
}