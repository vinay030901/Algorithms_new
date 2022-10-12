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
const int MAX_N = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ld EPS = 1e-9;

void solve()
{

}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    vector<int>arr={4,3,12,4,7,4,3};
    //print(arr);
    sort(all(arr));
    print(arr)

    // lower bound: it founds the element or the number greater than it
    // upper bound: if the element is present, even then it gives the next element


    // they return the location of the element
    auto it=lower_bound(all(arr),6);
    cout<<"\n"<<*it;
    it=lower_bound(all(arr),7);
    cout<<endl<<*it;
    it =upper_bound(all(arr),7);
    cout<<endl<<*it;
    it =upper_bound(all(arr),2);
    cout<<endl<<*it;

    // we can also use them in case of maps and set, but the syntax is different here
    set<int>s={4,5,2,3,8};
    auto itr=s.upper_bound(8);
    cout<<"\n"<<*itr;
}