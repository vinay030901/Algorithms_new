#include <bits/stdc++.h>
using namespace std;

#define ll long long


int main() {
  const int M = 1e9 + 7;
  int n;
  cin >> n;
  vector<int> A(n);
  for (int& x : A) cin >> x;

  int c0 = count(A.begin(), A.end(), 0);
  int cp = count_if(A.begin(), A.end(), [](int x) { return x > 0; });
  int cn = n - (c0 + cp);

  vector<ll> p2(n + 1);
  p2[0] = 1;
  for (int i = 1; i <= n; i++) {
    p2[i] = 2 * p2[i - 1] % M;
  }
  ll ans = (p2[c0] - 1) * (p2[cp] + p2[cn] - 1) % M;
  cout << ans;
  return 0;
}