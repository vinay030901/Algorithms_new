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
#define sees(s)                        \
    for (int i = 0; i < s.size(); i++) \
    {                                  \
        int x;                         \
        cin >> x;                      \
        s.insert(x);                   \
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
void solve()
{
    string str;
    cin >> str;
    unordered_map<char, int> rem, cost;
    int remb, rems, remc, costb, costs, costc;
    cin >> remb >> rems >> remc >> costb >> costs >> costc;
    rem['B'] = remb;
    rem['S'] = rems;
    rem['C'] = remc;
    cost['B'] = costb;
    cost['S'] = costs;
    cost['C'] = costc;
    int sum;
    cin >> sum;
    unordered_map<char, int> mp;
    for (auto it : str)
        mp[it]++;
    int ans = 0,no=0;
    while (sum > 0)
    {
        for (auto it : mp)
        {
            
            if (it.second <= rem[it.first])
            {
                rem[it.first] -= it.second;
            }
            else
            {
                int remaining =it.second- rem[it.first] ;
                rem[it.first] = 0;
                int toBuy = remaining * cost[it.first];
                if (sum >= toBuy)
                    sum -= toBuy;
                else
                    no=1;
            }
            if(no==1) break;
        }
        if(no==1) break;
        ans++;
    }
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