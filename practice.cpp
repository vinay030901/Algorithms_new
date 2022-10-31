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
#define print(v)                            \
	for (int i = 0; i < (int)v.size(); i++) \
		cout << v[i] << " ";
#define fr(n) for (int i = 0; i < n; i++)
#define fi(a, n) for (int i = a; i < n; i++)
#define pb push_back
#define f first
#define s second
#define el endl
#define vc vector<int>

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
int n, m, k;
vector<vector<int>> dp;
int bin_power_mod(int base, int power, int m = mod)
{
	base %= m;
	int res = 1;
	while (power > 0)
	{
		if (power & 1)
			res = res * base % m;
		base = base * base % m;
		power >>= 1;
	}
	return res;
}
int recur(int index, int moves)
{
	if (dp[index][moves] != -1)
		return dp[index][moves];
	int ans = 0;
	for (int i = 1; i <= m; i++)
	{
		if (index - i >= 0)
		{
			ans += recur(index - i, moves - 1) * bin_power_mod(m, mod - 2);
			ans %= mod;
		}
		if (index != n && i > (n - index))
		{
			int leftover_moves = i - (n - index);
			ans += recur(n - leftover_moves, moves - 1) * bin_power_mod(m, mod - 2);
			ans %= mod;
		}
	}
	return dp[index][moves] = ans;
}
void solve()
{
	// in this question, we need to find the probability of reaching the end of the line of squares when we can have a jump of atmost k
	// to do this question, we can divide this question to finding the probability of reaching the end of the line in exactly 1 move
	// or 2 move or 3 move, and then we will add all of them
	// so we now have the question to find the probability of reaching the end of the line in k die rolls
	// for every face value from 1 to n: we will compute i'
	// dp[i][j]=dp[i][j]+dp[i'][j-1]*1/m
	// to compute i'- it face value is x, either i' lie on the left side, then i'=i-x
	// when i' is on right side, if difference from i to n is y, then i'=n-(x-y)
	cin >> n >> m >> k;
	dp = vector<vector<int>>(n + 1, vector<int>(k + 1, -1));
	int finalAns = 0;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
		dp[i][0] = 0;
	for (int i = 1; i <= k; i++)
	{
		finalAns += recur(n, i);
		finalAns %= mod;
	}
	cout << finalAns;
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