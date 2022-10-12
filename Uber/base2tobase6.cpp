/*#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first 
#define ss second
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define FOR(i,N) for(i=0;i<(N);++i)
#define FORe(i,N) for(i=1;i<=(N);++i)
#define FORr(i,a,b) for(i=(a);i<(b);++i)
#define FORrev(i,N) for(i=(N);i>=0;--i)
#define F0R(i,N) for(int i=0;i<(N);++i)
#define F0Re(i,N) for(int i=1;i<=(N);++i)
#define F0Rr(i,a,b) for(ll i=(a);i<(b);++i)
#define F0Rrev(i,N) for(int i=(N);i>=0;--i)
#define all(v) (v).begin(),(v).end()
#define dbgLine cerr<<" LINE : "<<_LINE_<<"\n"
#define ldd long double

using namespace std;

const int Alp = 26;
const int __PRECISION = 9;
const int inf = 1e9 + 8;

const ldd PI = acos(-1);
const ldd EPS = 1e-7;

const ll MOD = 1e9 + 7;
const ll MAXN = 2e5 + 5;
const ll ROOTN = 320;
const ll LOGN = 18;
const ll INF = 1e18 + 1022;

const ll XX = (216LL * 216LL * 216LL * 216LL * 216LL * 216LL * 216LL);
int AA[101];

inline void test_case(){
    ll a = 0, b = 0;
    long long c = 0;
    int n;
    cin>>n;
    F0R(i, n){
        cin>>AA[i];
    }
    F0Rrev(i, n-1){
        c *= 2;
        c += AA[i];
        b <<= 1LL;
        b |= AA[i];
        a <<= 1LL;
        while(b >= XX){
            b -= XX;
            ++a;
        }
        //cerr<<"num = "<<a * XX + b<<'\n';
    }
    if(c <= 0){
        cout<<"0 ";
    }
    while(c > 0){
        cout<< (int)(c % 6) << ' ';
        c /= 6;
    }
    // while(a || b){
    //     cout<< b % 6 <<' ';
    //     b = (b + (a % 6) * XX) / 6;
    //     a /= 6;
    // }
    cout<<'\n';
}

signed main(){
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cerr<<XX<<'\n';
    int test_case_number;
    cin>>test_case_number;
    while(test_case_number--)
        test_case();
    return 0;
}*/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t; cin.tie(nullptr)->sync_with_stdio(false), cin >> t;
	while (t--) {
		string S; 
		cin >> S;
		int N = S.size();
		__int128 X = 0;
		for (int i = 0; i < N; ++i)
			if (X <<= 1, S[i] == '1')
				X |= 1;
		string ans;
		if (X == 0)
			ans = "0";
		else {
			while (X > 0)
				ans += char('0'+X%6), X /= 6;
			reverse(ans.begin(),ans.end()); }
		cout << ans << '\n'; }
	return 0; }