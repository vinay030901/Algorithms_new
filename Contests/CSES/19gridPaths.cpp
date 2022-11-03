#include <bits/stdc++.h>
using namespace std;

#define ar array
#define int long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define print(v)                            \
    for (int i = 0; i < (int)v.size(); i++) \
        cout << v[i] << " ";
#define fr(n) for (int i = 0; i < n; i++)
#define fi(a, n) for (int i = a; i < n; i++)
#define pb push_back
#define f first
#define s second
#define el endl
#define vi vector<int>
#define nl cout << '\n'
#define seea(a, x, y)           \
    for (int i = x; i < y; i++) \
    {                           \
        cin >> a[i];            \
    }
#define seev(v)                        \
    for (int i = 0; i < v.size(); i++) \
    {                                  \
        int x;                         \
        cin >> x;                      \
        v.push_back(x);                \
    }
#define sees(s, n)              \
    for (int i = 0; i < n; i++) \
    {                           \
        int x;                  \
        cin >> x;               \
        s.insert(x);            \
    }

const int MAX_N = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ld EPS = 1e-9;
static bool comparator(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first)
        return a.first > b.first;
    return a.first > b.first;
}
const int mod = 998244353;
int dir[5] = {-1, 0, 1, 0, -1};
const int pathLen = 48;
int p[48];
// we created a 9 length to add borders
const int grid_size = 9;
bool grid[grid_size][grid_size];
int fun(int ind, int row, int col)
{
    if ((grid[row][col - 1]) && (grid[row][col + 1]) && (!grid[row + 1][col]) && (!grid[row - 1][col]))
        return 0;
    if ((grid[row + 1][col]) && (grid[row - 1][col]) && (!grid[row][col + 1]) && (!grid[row][col - 1]))
        return 0;
    // if we reach the end and the length of indices travelled is not 48, then we return 0, else we return 1
    if (row == 7 && col == 1)
    {
        if (ind == pathLen)
            return 1;
        return 0;
    }
    // if the length of indices become 48 and we didn't reach the specified block, then we return 0
    if (ind == pathLen)
        return 0;
    grid[row][col] = true;
    int ret = 0;
    if (p[ind] < 4)
    {
        int nrow = row + dir[p[ind]];
        int ncol = col + dir[p[ind] + 1];
        if (!grid[nrow][ncol])
            ret += fun(ind + 1, nrow, ncol);
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + dir[i];
            int ncol = col + dir[i+1];
            if (grid[nrow][ncol])
                continue;
            else
                ret += fun(ind + 1, nrow, ncol);
        }
    }
    grid[row][col] = false;
    return ret;
}
void solve()
{
    // in this question, we need to find different ways in which we can traverse the whole grid and reach lower left corner
    // one of the ways is given
    // the most important part is we need to do this in only 48 steps, which is number of blocks-1
    // the description is already given
    string str;
    cin >> str;
    // converting the string to integer array, so that we don't have to compare
    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];
        if (c == 'U')
            p[i] = 0;
        else if (c == 'R')
            p[i] = 1;
        else if (c == 'D')
            p[i] = 2;
        else if (c == 'L')
            p[i] = 3;
        else
            p[i] = 4;
    }
    for (int i = 0; i < grid_size; i++)
    {
        grid[0][i] = true;
        grid[i][0] = true;
        grid[8][i] = true;
        grid[i][8] = true;
    }
    for (int i = 1; i <= 7; i++)
        for (int j = 1; j <= 7; j++)
            grid[i][j] = false;
    cout << fun(0, 1, 1);
}
int32_t main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}