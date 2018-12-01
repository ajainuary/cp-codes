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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n + 1, vector<int>(n + 1, -1));
  vector<int> s(n + 1, 0);
  for (int i = 0, a, b; i < m; ++i) {
    cin >> a >> b;
    g[min(a, b)][max(a, b)] = 1;
    g[max(a, b)][max(a, b)] = 1;
  }

  for (int i = 1; i <= n; ++i) {
    int cnt = 0;
    for (int j = 1; j <= n; ++j) {
      if (g[i][j] == 1) ++cnt;
    }
    if (cnt != 0) {
      cout << cnt << '\n';
      for (int j = 1; j <= n; ++j) {
        if (g[i][j] == 1) cout << i << ' ' << j << '\n';
      }
    } else {
      cout << 1 << '\n';
      cout << i << ' ' << i << '\n';
    }
  }
  return 0;
}