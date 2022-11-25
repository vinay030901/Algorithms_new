#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using namespace std;

#define ar array
#define int int
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
        cin >> v[i];                   \
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
int findGCD(vector<int> &nums)
{
    int maxi = *max_element(nums.begin(), nums.end()), mini = *min_element(nums.begin(), nums.end()), remain;
    while (mini)
    {
        remain = maxi % mini;
        maxi = mini;
        mini = remain;
    }
    return maxi;
}
const int mod = 998244353;

void solve()
{
    auto mergeSort = [&](vector<int> &a) -> int
    {
        int n = (int)a.size();

        int ans = 0, cnt1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {

                ans += cnt1;
            }
            else
            {

                cnt1++;
            }
        }

        return ans;
    };
    int n;
    cin >> n;
    vi v(n);
    int fz = -1, fo = -1;
    fr(n)
    {
        cin >> v[i];
        if (v[i] == 0 && fz == -1)
            fz = i;
        else if (v[i] == 1)
            fo = i;
    }
    int ans = mergeSort(v);
    if (fz != -1)
    {
        auto vc = v;
        vc[fz] = 1;
        ans = max(ans, mergeSort(vc));
    }
    if (fo != -1)
    {
        auto vd = v;
        vd[fo] = 0;
        ans = max(ans, mergeSort(vd));
    }
    cout << ans << "\n";
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
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}