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
void solve()
{
	char g[10][10];
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
			cin >> g[i][j];

	int ans = 0;
	for (int x1 = 1; x1 <= 9; x1++)
		for (int y1 = 1; y1 <= 9; y1++)
			for (int x2 = 1; x2 <= 9; x2++)
				for (int y2 = 1; y2 <= 9; y2++)
				{
					if (x1 == x2 && y1 == y2)
						continue;
					if (g[x1][y1] == '.' || g[x2][y2] == '.')
						continue;
					int x3 = x2 - (y2 - y1);
					int y3 = y2 - (x1 - x2);
					int x4 = x1 - (y2 - y1);
					int y4 = y1 - (x1 - x2);
					
					if (x3 >= 1 && x3 <= 9 && y3 >= 1 && y3 <= 9 && g[x3][y3] == '#')
						if (x4 >= 1 && x4 <= 9 && y4 >= 1 && y4 <= 9 && g[x4][y4] == '#')
						{
							cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<endl;
							ans++;
						}
							
				}
	cout << ans / 4;
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