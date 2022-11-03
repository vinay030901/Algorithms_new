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
void bin(int n)
{
    if (n > 1)
        bin(n >> 1);
    cout << (n & 1);
}
vector<string> generateArr(int n)
{
    if (n <= 0)
        return {"0"};
    else if (n == 1)
        return {"0", "1"};
    vector<string> recAns = generateArr(n - 1);
    vector<string> mainAns;
    // append 0 to first half
    for (int i = 0; i < recAns.size(); i++)
        mainAns.push_back("0" + recAns[i]);

    // append 1 to second half
    for (int i = recAns.size() - 1; i >= 0; i--)
        mainAns.push_back("1" + recAns[i]);

    return mainAns;
}
void solve1()
{
    int n;
    cin >> n;
    vector<string> arr = generateArr(n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}
void solve()
{
    // https://www.geeksforgeeks.org/binary-representation-of-a-given-number/
    int n;
    cin >> n;
    int limit = pow(2, n);
    for (int i = 0; i < limit; i++)
    {
        int val = (i ^ (i >> 1));
        cout << bitset<32>(val).to_string().substr(32 - n) << endl;
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