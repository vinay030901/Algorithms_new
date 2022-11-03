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
const int mod = 998244353;
void solve()
{
    // so we need to find the digit at nth position when all the integers are laid out
    //  and we have to do this in constant time as well
    /*now if the n<10-> then we can direcly give the number- (1,9)
    if number>=10 && number<=99 and we have 99-10+1=90 numbers with us, each digit cost 2- so 180 digits
    and the position is till 189(180+9)
    so if we get a position 16- then we know that is between 10 and 99
    so 16-10=6, and 6/2 is 3- 10+3=13-> so our digit is 1

    and we are going to use binary search for searching the solution, such 10 and 99-> then we will go 99-10/2 which is mid
    and if it is true, we will go to left or right depending on the need*/
    int t;
    cin >> t;
    vector<int> powers(19, 1);
    for (int i = 1; i < 19; i++)
        powers[i] = 10 * powers[i - 1];
    while (t--)
    {
        int n;
        cin >> n;
        int numdig = 0, digits = 0, predig = 0;
        for (int i = 1; i < 19; i++)
        {
            // now we need to find the range of that value n
            digits += (powers[i] - powers[i - 1]) * i;
            if (digits >= n)
            {
                numdig = i;
                break;
            }
            predig = digits;
        }
        int low = powers[numdig - 1];
        int high = powers[numdig] - 1;
        int ans = 0;
        int startAns = 0;
        while (low <= high)
        {
            int mid = (high + low) / 2;
            int startPos = (mid - powers[numdig - 1]) * numdig + predig + 1;
            if (startPos <= n)
            {
                if (mid > ans)
                {
                    ans = mid;
                    startAns = startPos;
                }
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        string number = to_string(ans);
        cout << number[n - startAns] << endl;
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