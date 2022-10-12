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

const int MAX_N = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ld EPS = 1e-9;

void solve()
{
    // we can think of the input as chess like or not like

    // if it chess like: means, then we can just mark the whole board like a chess board, so two colours will go on
    // diagonally and no two same adjacent will be there

    // no second case be like: they are not like a chess board, that is the given values are in same diagonal
    // then answer will not be two colours now, we can't will it using two colours Only.

    // so what we will do is take the third colour now, we will fill the matrix in chess like fashion using colour 1 and 3 now
    // and that will be done. We will have only a single value with colour 2.

    // another important aspect is which cell will get colour 1 and which cell will get colour 2, then we can number the cells
    // here, will add the row no and col no and write it is even or odd, we can use the info for deciding colours

    int m, n;
    cin >> n >> m;
    int arr[n + 1][m + 1];
    int x1, y1, x2, y2;
    cin >> x1 >> y1;
    arr[x1][y1] = 1;
    cin >> x2 >> y2;
    arr[x2][y2] = 2;

    bool chessLike = ((x1 + y1) & 1) != ((x2 + y2) & 1);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if ((i == x1 and j == y2) or (i == x2 and j == y2))
                continue;
            if ((((i + j) & 1) == ((x1 + y1) & 1)))
                arr[i][j] = 1;
            else
                arr[i][j] = (chessLike ? 2 : 3);
        }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
}

int32_t main()
{
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