#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int mx = 0, mn = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        mn = min(mn, arr[i]);
        mx = max(mx, arr[i] - mn);
    }
    if (mx == 0)
        cout << "Not Possible";
    else
    {
        cout << "Possible\n"
             << mx;
    }
}
