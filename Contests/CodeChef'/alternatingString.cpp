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
#define pb push_back
#define f first
#define s second
#define el endl

const int MAX_N = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ld EPS = 1e-9;

void solve()
{
    string s;
    cin>>s;
    int z=0,o=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='0') z++;
        else o++;
    }
    string str="";
    int f=0;
    if(o>z) f=1;
    while(o>0 and z>0)
    {
        if(f==0)
        {
            str+="1";
            o--;
            f=1;
        }
        else{
            str+="0";
            z--;
            f=0;
        }
    }
    cout<<str.length()<<endl;
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