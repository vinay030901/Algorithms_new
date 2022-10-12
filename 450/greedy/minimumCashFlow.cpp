#include <bits/stdc++.h>
using namespace std;
int findmin(int amount[], int n)
{
    int mn = 0;
    for (int i = 1; i < n; i++)
        if (amount[i] < amount[mn])
            mn = i;
    return mn;
}
int findmax(int amount[], int n)
{
    int mx = 0;
    for (int i = 1; i < n; i++)
        if (amount[i] > amount[mx])
            mx = i;
    return mx;
}
void mincash(int amount[], int n)
{
    int mn = findmin(amount, n);
    int mx = findmax(amount, n);
    if (amount[mn] == 0 || amount[mx] == 0)
        return;
    int x = min(-amount[mn], amount[mx]);
    amount[mx] -= x;
    amount[mn] += x;
    cout << "friend " << mn + 1 << " pays " << abs(x) << " to friend " << mx + 1 << endl;
    mincash(amount, n);
}
void minflow(int cash[][3], int n)
{
    int amount[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            amount[i] += (cash[j][i] - cash[i][j]);
        }
    mincash(amount, n);
}
int main()
{
    int cash[3][3] = {{0, 2000, 4000},
                      {0, 0, 3000},
                      {0, 0, 0}};
    int n = 3;
    minflow(cash, n);
}