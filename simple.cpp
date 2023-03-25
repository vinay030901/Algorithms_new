#include <bits/stdc++.h>
using namespace std;
string p = "";
void fun(string &a, string &b, int &m, int &n)
{
    if (a == b)
    {
        cout << "YES\n"
             << a << endl;
        return;
    }
    if (m == 1 && n == 1)
    {
        if (a == b)
            cout << "YES\n"
                 << a << endl;
        else
            cout << "NO\n";
        return;
    }
    if (a[0] == b[0])
    {
        cout << "YES\n"
             << a[0] << "*" << endl;
        return;
    }
    if (a[m - 1] == b[n - 1])
    {
        cout << "YES\n"
             << "*" << a[m - 1] << endl;
        return;
    }
    for (int fir = 0; fir < m; fir++)
        for (int sec = 0; sec < n; sec++)
        {
            if (a[fir] == b[sec])
            {
                if (fir < m - 1 && sec < n - 1)
                {
                    if (a[fir + 1] == b[sec + 1])
                    {
                        cout << "YES\n"
                             << "*" << a[fir] << a[fir + 1] << "*" << endl;
                        return;
                    }
                }
            }
        }
    cout << "NO\n";
}
void solve()
{
    string a, b;
    cin >> a >> b;
    int m = a.length(), n = b.length();
    fun(a, b, m, n);
}
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}