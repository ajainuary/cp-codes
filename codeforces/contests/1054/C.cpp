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
  vector<pair<int, int>> c(n);
  for (auto &x : c) cin >> x.first;
  for (auto &x : c) cin >> x.second;
  for (int i = 0; i < n; ++i) {
    int left = 0, right = 0;
    for (int j = 0; j < i; ++j)
      if (c[j].first + c[j].second < c[i].first + c[i].second) ++left;
    for (int j = i + 1; j < n; ++j)
      if (c[j].first + c[j].second < c[i].first + c[i].second) ++right;
    if (left != c[i].first || right != c[i].second) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  for (auto &x : c) cout << n - (x.first + x.second) << ' ';
  cout << '\n';
  return 0;
}