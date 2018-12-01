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
  int t;
  cin >> t;
  while (t--) {
    long long int n, x, y, d;
    cin >> n >> x >> y >> d;
    n--;
    x--;
    y--;
    if (abs(y - x) % d == 0)
      cout << abs(y - x) / d << endl;
    else {
      long long int l = INT_MAX;
      long long int r = INT_MAX;
      if (y % d == 0) {
        l = (x / d + ((x % d == 0) ? 0 : 1)) + (y / d);
      }
      if ((n - y) % d == 0) {
        r = ((n - x) / d + (((n - x) % d == 0) ? 0 : 1)) + ((n - y) / d);
      }
      if (min(l, r) == INT_MAX)
        cout << -1 << endl;
      else
        cout << min(l, r) << endl;
    }
  }
  return 0;
}