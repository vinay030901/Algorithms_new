#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> v = {1, 1, 4, 4, 9, 9, 8, 8, 5, 3, 3, 6, 6};
    int sum = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        sum ^= v[i];
    }
    cout << sum;
}