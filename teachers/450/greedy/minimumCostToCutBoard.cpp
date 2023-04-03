#include <bits/stdc++.h>
using namespace std;
bool comparison(int a, int b)
{
    return a > b;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n, cost = 0;
        cin >> m >> n;
        m--;
        n--;
        int am[m], an[n];
        for (int i = 0; i < m; i++)
            cin >> am[i];
        for (int i = 0; i < n; i++)
            cin >> an[i];
        sort(am, am + m, comparison);
        sort(an, an + n, comparison);
        int hz = 1, vr = 1;
        int i = 0, j = 0;
        while (i < m && j < n)
        {
            if (am[i] >= an[j])
            {
                cost += am[i] * vr;
                hz++;
                i++;
            }
            else
            {
                cost += an[j] * hz;
                vr++;
                j++;
            }
        }
        while (i < m)
        {
            cost += am[i] * vr;
            hz++;
            i++;
        }
        while (j < n)
        {
            cost += an[j] * hz;
            vr++;
            j++;
        }
        cout << cost << endl;
    }
}