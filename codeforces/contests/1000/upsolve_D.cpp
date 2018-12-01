#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define sz(a) ll(a.size())
#define dbg(x) \
  { cerr << #x << " = " << x << endl; }

const int MOD = 998244353;
vector<vector<int>> cache(1003, vector<int>(1003, -1));

long long int C(int n, int r) {
  if (n < r) return 0;
  if (r > n - r) r = n - r;
  if (r == 0) return 1;
  if (r == 1) return n;
  if (cache[n][r] != -1) return cache[n][r];
  cache[n][r] = (C(n - 1, r) + C(n - 1, r - 1)) % MOD;
  return cache[n][r];
}
int main() {
  FAST_IO
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  vector<long long int> sub(n, 0);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[n - 1 - i] > 0 && a[n - 1 - i] <= i) {
      sub[i] = C(i, a[n - 1 - i]);
      for (int j = i - a[n - 1 - i] - 1; j >= 0; --j)
        sub[i] = (sub[i] + (C(i - j - 1, a[n - 1 - i]) * sub[j]) % MOD) % MOD;
    }
    ans = (ans + sub[i]) % MOD;
  }
  cout << ans << endl;
  return 0;
}