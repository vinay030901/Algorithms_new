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
void solve()
{
    int n, q;
    cin >> n >> q;
    int x;
    vector<int> arr(n + 1), position(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        position[arr[i]] = i;
    }
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        ans += (position[i] > position[i + 1]);
    }
    int l, r;
    set<pair<int, int>> pairs;
    fr(q)
    {
        cin >> l >> r;
        if (arr[l] + 1 <= n)
            pairs.insert({arr[l], arr[l] + 1});
        if (arr[l] - 1 >= 1)
            pairs.insert({arr[l] - 1, arr[l]});
        if (arr[r] + 1 <= n)
            pairs.insert({arr[r], arr[r] + 1});
        if (arr[r] - 1 >= 1)
            pairs.insert({arr[r] - 1, arr[r]});
        for (auto it : pairs)
        {
            ans -= position[it.first] > position[it.second];
        }
        swap(arr[l], arr[r]);
        position[arr[l]] = l;
        position[arr[r]] = r;
        for (auto it : pairs)
        {
            ans += position[it.first] > position[it.second];
        }
        pairs.clear();
        cout << ans << "\n";
    }
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