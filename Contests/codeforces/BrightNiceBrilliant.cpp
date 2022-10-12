#include <bits/stdc++.h>
using namespace std;
void fun()
{
    int n;
    cin >> n;
    if (n == 1)
        cout << "1\n";
    else if (n == 2)
    {
        cout << "1\n"
             << "1 1\n";
    }
    else
    {
        cout << "1\n"
             << "1 1\n";
        for (int i = 3; i <= n; i++)
        {
            cout << "1 ";
            for (int j = 1; j < i - 1; j++)
                cout << "0 ";
            cout << "1\n";
        }
    }
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