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
#define ar array
#define int long long
#define ld long double
#define ull unsigned long long
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

ull cut(vector<ull>v,ull mid)
{
    ull sum=0;
    for(ull i=(ull)sza(v)-1;i>=0;i--)
    {
        if(mid>=v[i]) return sum;
        sum+=(v[i]-mid);
    }
    return sum;
}
ull search(ull m,vector<ull>v,ull mx)
{
    ull low=0,high=mx;
    while(high-low>1)
    {
        ull mid=(high+low)/2;
        ull ans=cut(v,mid);
        if(ans==m) return mid;
        else if(ans>m) low=mid;
        else high=mid;
    }
    return -1;
}
    long long count(string a, string b)
{
    long long m = a.length();
    long long n = b.length();
 
    long long lookup[100000][100000];
    memset(lookup,0,sizeof(lookup));
    for (long long i = 0; i <= n; ++i)
        lookup[0][i] = 0;
 
    // If second string is empty
    for (long long i = 0; i <= m; ++i)
        lookup[i][0] = 1;
    for (long long i = 1; i <= m; i++)
    {
        for (long long j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
                lookup[i][j] = lookup[i - 1][j - 1] +
                               lookup[i - 1][j];
                 
            else
                lookup[i][j] = lookup[i - 1][j];
        }
    }
 
    return lookup[m][n];
}
    long long maximumSubsequenceCount(string text, string pattern) {
        string moda=pattern[0]+text;
        string modb=text+pattern[1];
        long long ma=count(moda,pattern);
        long long mb=count(modb,pattern);
        if(ma>=mb) return ma;
        return mb;
    }
void solve()
{  
    /*ull m,n;
    cin>>n>>m;
    vector<ull>v(n);
    fr(n) cin>>v[i];
    sort(all(v));
    ull mx=v[sza(v)-1];
    cout<<search(m,v,mx);*/
    string t="abdcdbc",p="ac";
    long long ans=maximumSubsequenceCount(t,p);
    cout<<ans;
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