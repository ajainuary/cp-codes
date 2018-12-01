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
    int period = 0;
    bool possible = true;
    if (positions.size() > 1) {
      for (deque<int>::reverse_iterator j = positions.rbegin();
           next(j) != positions.rend() && possible; ++j) {
        int nk = *j - positions.front() - (a[*j] - a[positions.front()]);
        if (nk < 0) possible = false;
        if (nk == 0) continue;
        period = __gcd(period, nk);
        if (period < max_a) possible = false;
      }
    }
    if (possible) {
      if (period == 0)
        cout << "inf\n";
      else
        cout << period << '\n';
    } else
      cout << "impossible\n";
  }
  return 0;
}