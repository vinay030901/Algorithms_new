/*
Chef has the binary representation SS of a number XX with him. He can modify the number by applying the following operation exactly once:

Make X := X \oplus \lfloor \frac{X}{2^{Y}} \rfloorX:=X⊕⌊
2
Y

X
​
 ⌋, where (1 \leq Y \leq |S|)(1≤Y≤∣S∣) and \oplus⊕ denotes the bitwise XOR operation.
Chef wants to minimize the value of XX after performing the operation. Help Chef in determining the value of YY which will minimize the value of XX after the operation.

Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
Each test case consists of two lines of inputs:
The first line contains the length of the binary string SS.
The second line contains the binary string SS.
Output Format
For each test case, output on a new line, the value of YY which will minimize the value of XX after the operation.

Constraints
1 \leq T \leq 5 \cdot 10^41≤T≤5⋅10
4

1 \leq |S| \leq 10^51≤∣S∣≤10
5

The sum of |S|∣S∣ over all test cases won't exceed 5 \cdot 10^55⋅10
5
 .
SS contains the characters 00 and 11 only.
Sample 1:
Input
Output
4
2
10
2
11
3
101
3
110
2
1
2
1
Explanation:
Test case 11: Since S = 10S=10 is the binary representation of 22, the current value of X = 2X=2. On choosing Y = 2Y=2, XX becomes 2 \oplus \lfloor \frac{2}{2^{2}} \rfloor = 22⊕⌊
2
2

2
​
 ⌋=2. We can show that this is the minimum value of XX we can achieve after one operation.

Test case 22: Since S = 11S=11 is the binary representation of 33, the current value of X = 3X=3. On choosing Y = 1Y=1, XX becomes 3 \oplus \lfloor \frac{3}{2^{1}} \rfloor = 23⊕⌊
2
1

3
​
 ⌋=2. We can show that this is the minimum value of XX we can achieve after one operation.

Test case 33: Since S = 101S=101 is the binary representation of 55, the current value of X = 5X=5. On choosing Y = 2Y=2, XX becomes 5 \oplus \lfloor \frac{5}{2^{2}} \rfloor = 45⊕⌊
2
2

5
​
 ⌋=4. We can show that this is the minimum value of XX we can achieve after one operation.

Test case 44: Since S = 110S=110 is the binary representation of 66, the current value of X = 6X=6. On choosing Y = 1Y=1, XX becomes 6 \oplus \lfloor \frac{6}{2^{1}} \rfloor = 56⊕⌊
2
1

6
​
 ⌋=5. We can show that this is the minimum value of XX we can achieve after one operation.*/

/*in this solution, we need to minimize the number, so we should flip the rightmost one digit to make it small
but the value of y should be atleast 1, so we can't flip the first digit, that is, we can't right shift 0 times
therefore we will start our search from one only and then search for first one*/

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
#define double long double
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
#define vc vector<int>

const int MAX_N = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double EPS = 1e-9;

void solve()
{
    string s;
    int n;
    cin >> n >> s;
    int cnt = 1;
    fi(1, n) if (s[i] == '1') break;
    else cnt++;
    cout << cnt << endl;
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
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}