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
  vector<pair<int, int>> ls(n);
  for (auto &x : ls) cin >> x.first >> x.second;
  set<int> wcd;
  wcd.insert(ls[0].first);
  wcd.insert(ls[0].second);
  for (int i = 1; i < n; ++i) {
    for (auto j = wcd.begin(); j != wcd.end(); ++j) {
      if (__gcd(*j, ls[i].first) == 1) {
        if (__gcd(*j, ls[i].second) != 1) {
          int tmp = *j;
          wcd.erase(j);
          wcd.insert(__gcd(tmp, ls[i].second));
        } else {
          wcd.erase(j);
        }
      } else {
        int tmp = *j;
        wcd.erase(j);
        wcd.insert(__gcd(tmp, ls[i].first));
        wcd.insert(__gcd(tmp, ls[i].second));
      }
    }
  }
  for (auto j = wcd.begin(); j != wcd.end(); ++j) {
    if (*j != 1) {
      cout << *j << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}