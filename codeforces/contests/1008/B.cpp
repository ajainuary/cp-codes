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
  int n;
  cin >> n;
  vector<pair<int, int>> r(n);
  for (auto &x : r) cin >> x.first >> x.second;
  int h = max(r[0].first, r[0].second);
  for (int i = 1; i < n; ++i) {
    if (max(r[i].first, r[i].second) > h) {
      if (min(r[i].first, r[i].second) > h) {
        cout << "NO\n";
        return 0;
      }
      h = min(r[i].first, r[i].second);
    } else
      h = max(r[i].first, r[i].second);
  }
  cout << "YES\n";
  return 0;
}