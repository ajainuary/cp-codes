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
  vector<string> g(n);
  for (int i = 0; i < n; ++i) {
    cin >> g[i];
  }
  vector<vector<char>> c(n, vector<char>(m, '.'));
  for (int i = 0; i < n - 2; ++i) {
    for (int j = 0; j < m - 2; ++j) {
      bool place = true;
      for (int p = 0; p < 3; ++p) {
        for (int q = 0; q < 3; ++q) {
          if (p != 1 || q != 1) {
            if (g[i + p][j + q] != '#') place = false;
          }
        }
      }
      if (place) {
        for (int p = 0; p < 3; ++p) {
          for (int q = 0; q < 3; ++q) {
            if (p != 1 || q != 1) {
              c[i + p][j + q] = '#';
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (c[i][j] != g[i][j]) {
        cout << "NO\n";
        return 0;
      }
    }
  }
  cout << "YES\n";
  return 0;
}