#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, minXor = 10000000;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int xorArr = 0;
    for (int i = 0; i < n; i++)
        xorArr ^= arr[i];
    for (int i = 0; i < n; i++)
        minXor = min(minXor, (xorArr ^ arr[i]));
    cout << minXor;
}