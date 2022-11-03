#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define int long long
#define ld long double
#define sz(x) ((int)x.size())
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
int recur(int i, vector<int> &arr, int target)
{
    if (target < 0)
        return INT_MAX;
    if (target == 0)
        return 0;
    if (i == 0)
    {
        if (target >= arr[i])
            return target - arr[i];
        else
            return target;
    }

    int notTake = recur(i - 1, arr, target);
    int take = INT_MAX;
    if (arr[i] <= target)
        take = recur(i - 1, arr, target - arr[i]);
    return min(take, notTake);
}
int ans = 0;
bool isValid(int row, int col, vector<string> &board, int n)
{
    int duprow = row, dupcol = col;
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }
    row = duprow;
    col = dupcol;
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }
    col = dupcol;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }
    return true;
}
void solve(int col, vector<string> &board, int n)
{
    if (col == n)
    {
        ans++;
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isValid(row, col, board, n) && board[row][col] != '*')
        {
            board[row][col] = 'Q';
            solve(col + 1, board, n);
            board[row][col] = '.';
        }
    }
}
void solve()
{
    char c;
    vector<string> board(8);
    for (int i = 0; i < 8; i++)
    {
        string s = "";
        for (int j = 0; j < 8; j++)
        {
            cin >> c;
            s += c;
        }
        board[i] = s;
    }
    solve(0, board, 8);
    cout << ans;
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