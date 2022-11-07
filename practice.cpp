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
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int findGCD(vector<int> &n)
{
    gcd(*min_element(begin(n), end(n)), *max_element(begin(n), end(n)));
}
const int mod = 998244353;
int is, js;
int findways(int n, int gcd)
{
    int ans = 0;
    while (n != gcd && n)
    {
        if (n % 2 == 0)
            n /= 2;
        else if (n % 3 == 0)
            n /= 3;
        else
            return -1;
        ans++;
    }
    return ans;
}
int n, m;
bool check(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &vis)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    if (grid[i][j] == '#' || vis[i][j])
        return false;
    return true;
}
bool recur(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &vis, int count)
{
    if (i == is && j == js)
    {
        if (count >= 4)
            return 1;
        return 0;
    }
    int a1, a2, a3, a4;
    if (check(i + 1, j, grid, vis))
    {
        vis[i + 1][j] = 1;
        a1 = recur(i + 1, j, grid, vis, count + 1);
    }
    if (check(i - 1, j, grid, vis))
    {
        vis[i - 1][j] = 1;
        a2 = recur(i - 1, j, grid, vis, count + 1);
    }
    if (check(i, j + 1, grid, vis))
    {
        vis[i][j + 1] = 1;
        a3 = recur(i, j + 1, grid, vis, count + 1);
    }
    if (check(i, j - 1, grid, vis))
    {
        vis[i][j - 1] = 1;
        a4 = recur(i, j - 1, grid, vis, count + 1);
    }
    return a1 || a2 || a3 || a4;
}
void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'S')
            {
                is = i;
                js = j;
            }
        }
    }
    vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));
    if (recur(is + 1, js, grid, vis, 1) != 0)
    {
        cout << "Yes";
        return;
    }
    if (recur(is, js + 1, grid, vis, 1) != 0)
    {
        cout << "Yes";
        return;
    }
    if (recur(is - 1, js, grid, vis, 1) != 0)
    {
        cout << "Yes";
        return;
    }
    if (recur(is, js - 1, grid, vis, 1) != 0)
    {
        cout << "Yes";
        return;
    }
    cout << "No";
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