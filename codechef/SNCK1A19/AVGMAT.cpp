#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define dbg(x) \
  { cerr << #x << " = " << x << endl; }

int main() {
  FAST_IO
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int max_d = n + m - 1;
    vector<string> grid(n);
    for (auto &x : grid) cin >> x;
    vector<vector<vector<int>>> down(
        n, vector<vector<int>>(m, vector<int>(max_d, 0)));
    vector<vector<vector<int>>> up(
        n, vector<vector<int>>(m, vector<int>(max_d, 0)));
    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(m, vector<int>(max_d, 0)));
    for (int i = n - 1; i >= 0; --i)
      for (int j = m - 1; j >= 0; --j) {
        if (grid[i][j] == '1') down[i][j][0] += 1;
        if (i == n - 1) continue;
        for (int k = 1; k < max_d; ++k) down[i][j][k] = down[i + 1][j][k - 1];
      }
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == '1') up[i][j][0] += 1;
        if (i == 0) continue;
        for (int k = 1; k < max_d; ++k) up[i][j][k] = up[i - 1][j][k - 1];
      }
    for (int i = n - 1; i >= 0; --i)
      for (int j = m - 1; j >= 0; --j) {
        for (int k = 1; k < max_d; ++k) dp[i][j][k] += up[i][j][k];
        for (int k = 0; k < max_d; ++k) dp[i][j][k] += down[i][j][k];
        if (j == m - 1) continue;
        for (int k = 1; k < max_d; ++k) dp[i][j][k] += dp[i][j + 1][k - 1];
      }
    vector<int> ans(max_d, 0);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (grid[i][j] == '1')
        {
          for (int k = 1; k < max_d; ++k) ans[k] += dp[i][j][k];
          for (int k = 1; k < max_d; ++k) ans[k] -= up[i][j][k];
        }
    for (int i = 1; i < max_d; ++i) cout << ans[i] << ' ';
    cout << '\n';
  }
  return 0;
}