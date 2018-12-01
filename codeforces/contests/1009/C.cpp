#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define sz(a) ll(a.size())
#define dbg(x) \
  { cerr << #x << " = " << x << endl; }

int main() {
  FAST_IO
  long double n, m;
  cin >> n >> m;
  long double min = LLONG_MAX;
  long double max = LLONG_MIN;
  long double sum;
  for (long double i = 1; i <= n; ++i) {
    sum = (n - i) * (n - i + 1) + i * (i - 1);
    sum = sum / 2;
    if (sum > max) max = sum;
    if (sum < min) min = sum;
  }
  long double maxsum = 0;
  for (long long int i = 0, x, d; i < m; ++i) {
    cin >> x >> d;
    maxsum += (x * n) + d * ((d > 0) ? max : min);
  }
  long double ans = maxsum / n;
  dbg(maxsum) dbg(min) dbg(max) cout.precision(100);
  cout << setprecision(100) << ans << endl;
  return 0;
}