#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {5, 3, 6, 9, 3, 7, 3, 7, 23, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int mx = arr[0], mn = arr[0];
    for (int i = 1; i < n; i++)
    {
        mx = max(mx, arr[i]);
        mn = min(mn, arr[i]);
    }
    cout << "maximum number: " << mx << endl;
    cout << "minimum number: " << mn << endl;
}
/*
mx=*max_element(arr,arr+n);
mn=*min_element(arr,arr+n);*/