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
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define print(v) for(int i=0;i<(int)v.size();i++) cout<<v[i]<<" ";
#define fr(n) for(int i=0;i<n;i++)
#define fi(a,n) for(int i=a;i<n;i++)
#define push_back pb
#define first f
#define second s

const int MAX_N = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ld eps = 1e-9;

double ep=1e-6;
double multiply(double mid,double n)
{
    double ans=1;
    for(int i=0;i<n;i++)
    ans*=mid;
    return ans;
}
void solve()
{
    double n,root;
    cin>>n>>root;
    double low=1,high=n,mid;
    while(high-low>ep)
    {
        mid=(high+low)/2;
        if(multiply(mid,root)<n) low=mid;
        else high=mid;
    }
    cout<<low<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}