#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);

int main() {
  // FAST_IO
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    vector<vector<int>> g(n, vector<int>(m));
    for (auto &x : g)
      for (auto &y : x) cin >> y;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (!(i == 0 || i == n - 1) && g[i - 1][j] == g[i + 1][j]) {
          cout << g[i - 1][j] << '=' << g[i + 1][j] << '\n';
          cout << t << '@' << i << ' ' << j << endl;
          cout << n << ' ' << m << endl;
          for (int i = 0; i < n; ++i)
          {
            for (int j = 0; j < m; ++j)
            {
              cout << g[i][j] << ' ';
            }
            cout << endl;
          }
          return 1;
        }
        if (!(j == 0 || j == m - 1) && g[i][j - 1] == g[i][j + 1]) {
          cout << g[i][j - 1] << '=' << g[i][j + 1] << '\n';
          cout << t << '@' << i << ' ' << j << endl;
          cout << n << ' ' << m << endl;
          return 1;
        }
      }
    }
    cout << "OK" << endl;
  }
  return 0;
}