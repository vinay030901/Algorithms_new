#include <bits/stdc++.h>
using namespace std;
int md = 1e9 + 7;
int fun(int n, int k)
{
    if (n == 2)
        return k;
    int sum = 1;
    for (int i = 1; i < n; i++)
        sum = (sum * k) % md;
    return sum + 1;
}
int main()
{
    int n, k;
    cin >> n >> k;
    cout << fun(n, k);
}