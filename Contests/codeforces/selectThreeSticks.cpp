#include <bits/stdc++.h>
using namespace std;
void fun()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int mn = INT_MAX;
    int res = 0;
    vector<int> arr;
    for (int i = 1; i < n; i++)
        arr.push_back(v[i] - v[i - 1]);
    for (int i = 1; i < arr.size(); i++)
        mn = min(mn, arr[i] + arr[i - 1]);
    cout << mn << endl;
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        fun();
    }
}