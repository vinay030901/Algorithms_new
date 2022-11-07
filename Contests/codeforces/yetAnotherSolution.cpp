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
    // when the size of the query is odd then the answer is xor of all the element of the query
    /*
    for example we have 5 element, then xor of all those element is y
    now we take 3 element and their xor is x- so we have x x x a b
    now we take (x,a,b) and thier xor is y- so we have (x x y) and xor of all of them is y because x^x is 0*/

    /*now we talk about query of even size- for example 4

    here we can't make the value zero if take 3 and 1-
    a b c d
    x x x d(first 3)
    x d d d(last 3)
    x x x d(first 3)
    so we can't find the answer in this case
    therefore we will divide the even value into groups of odd values and then find the answer like we are gonna find in odd case(which is finding the xor of all the elements)

    now we will find the cases

    ODD-
    y=0(if all the elements are zero, then answer is zero)-0
    if(all elements are not zero)-1
    y!=0

    EVEN-
    y=0- all elements are zero- 0
    else if last element is 0 or first element is zero- then 1
    if not- then we have to divide it into two odd length xor with value 0- then answer is 2
    if we can't do it- we have to print -1*/
    int i, j, l, r, x;
    // zero array to count the number of zeros till i, for the case to check the number of zero in a range and if all are zeros in the query
    // pre array is used to find the prefix of element till ith position
    // using this, we can easily find the xor of range
    int a[n + 1], zero[n + 1], pre[n + 1];
    for (i = 1; i <= n; i++)
        cin >> a[i];
    if (a[1] == 0)
        zero[1] = 1;
    else
        zero[1] = 0;
    pre[1] = a[1];
    zero[0] = pre[0] = a[0] = 0;
    for (int i = 2; i <= n; i++)
    {
        pre[i] = pre[i - 1] ^ a[i];
        if (a[i] == 0)
            zero[i] = 1 + zero[i - 1];
        else
            zero[i] = zero[i - 1];
    }
    map<int, vector<int>> mp[2];
    for (int i = 1; i <= n; i++)
    {
        if ((i & 1) == 0)
            mp[0][pre[i]].push_back(i); // so this list denote the position where prefix of i is pre[i]
        // and we have two cases too, that is 0 and 1 for odd and even size
        else
            mp[1][pre[i]].push_back(i);
    }
    while (q--)
    {
        cin >> l >> r;
        x = pre[r] ^ pre[l - 1];
        if (x != 0)
        {
            cout << "-1\n";
            continue;
        }
        if (zero[r] - zero[l - 1] == r - l + 1)
        {
            cout << "0\n";
            continue;
        }
        if ((r - l + 1) & 1)
        {
            cout << "1\n";
            continue;
        }
        if (a[r] == 0 || a[l] == 0)
        {
            cout << "1\n";
            continue;
        }
        vector<int>::iterator it;
        if (l % 2 == 0)
        {
            it = lower_bound(mp[0][pre[l - 1]].begin(), mp[0][pre[l - 1]].end(), l);
            if (it != mp[0][pre[l - 1]].end())
                i = mp[0][pre[l - 1]][it - mp[0][pre[l - 1]].begin()];
            else
                i = -1;
            if (i < r && i > l)
                cout << "2\n";
            else
                cout << "-1\n";
        }
        else
        {
            it = lower_bound(mp[1][pre[l - 1]].begin(), mp[1][pre[l - 1]].end(), l);
            if (it != mp[1][pre[l - 1]].end())
                i = mp[1][pre[l - 1]][it - mp[1][pre[l - 1]].begin()];
            else
                i = -1;
            if (i < r && i > l)
                cout << "2\n";
            else
                cout << "-1\n";
        }
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