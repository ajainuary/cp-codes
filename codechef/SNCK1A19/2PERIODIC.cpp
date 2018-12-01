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
    int n, max_a = -1;
    cin >> n;
    vector<int> a(n);
    deque<int> positions;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i] > 0) positions.push_back(i);
      if (a[i] > max_a) max_a = a[i];
    }
    int period = -1;
    bool possible = true;
    if (positions.size() > 1)
      for (deque<int>::iterator j = positions.begin();
           next(j) != positions.end() && possible; ++j) {
        int nk = *next(j) - *j - abs(a[*next(j)] - a[*j]);
        if (nk < 0) possible = false;
        if (nk == 0) nk = *next(j) - *j + 1;
        if (period != -1)
          period = __gcd(period, nk);
        else
          period = nk;
      }
    // Test
    // int idx = 0;
    // while (a[idx] < 0) ++idx;
    // for (int i = idx, cur = a[idx]; i < n && possible; ++i) {
    //   cur = (period > 0) ? (a[idx] + i - (idx + 1)) % period + 1
    //                      : a[idx] + i - (idx + 1) + 1;
    //   if (a[i] >= 0 && a[i] != cur) possible = false;
    // }
    if (possible) {
      if (period == -1)
        cout << "inf\n";
      else
        cout << period << '\n';
    } else
      cout << "impossible\n";
  }
  return 0;
}