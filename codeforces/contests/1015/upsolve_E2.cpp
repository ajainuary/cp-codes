#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for (auto &x : grid) cin >> x;
  vector<vector<int>> up(n, vector<int>(m, 0));
  vector<vector<int>> left(n, vector<int>(m, 0));
  vector<vector<int>> down(n, vector<int>(m, 0));
  vector<vector<int>> right(n, vector<int>(m, 0));
  for (int i = 0; i < m; ++i) {
    if (grid[0][i] == '*') up[0][i] = 1;
    if (grid[n - 1][i] == '*') down[n - 1][i] = 1;
  }
  for (int i = 0; i < n; ++i) {
    if (grid[i][0] == '*') left[i][0] = 1;
    if (grid[i][m - 1] == '*') right[i][m - 1] = 1;
  }
  for (int i = 1; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (grid[i][j] == '*') up[i][j] = up[i - 1][j] + 1;
  for (int i = 1; i < m; ++i)
    for (int j = 0; j < n; ++j)
      if (grid[j][i] == '*') left[j][i] = left[j][i - 1] + 1;
  for (int i = n - 2; i >= 0; --i)
    for (int j = 0; j < m; ++j)
      if (grid[i][j] == '*') down[i][j] = down[i + 1][j] + 1;
  for (int i = m - 2; i >= 0; --i)
    for (int j = 0; j < n; ++j)
      if (grid[j][i] == '*') right[j][i] = right[j][i + 1] + 1;
  vector<pair<pair<int, int>, int>> stars;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (min(min(up[i][j], down[i][j]), min(left[i][j], right[i][j])) > 1)
        stars.push_back(
            {{i, j},
             min(min(up[i][j], down[i][j]), min(left[i][j], right[i][j])) - 1});
  vector<vector<int>> h(n, vector<int>(m, 0));
  vector<vector<int>> v(n, vector<int>(m, 0));
  for (auto &x : stars) {
    ++v[x.first.first - x.second][x.first.second];
    if (x.first.first + x.second + 1 < n)
      --v[x.first.first + x.second + 1][x.first.second];
    ++h[x.first.first][x.first.second - x.second];
    if (x.first.second + x.second + 1 < m)
      --h[x.first.first][x.first.second + x.second + 1];
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (i > 0) v[i][j] += v[i - 1][j];
      if (j > 0) h[i][j] += h[i][j - 1];
      if (grid[i][j] == '*' && !(h[i][j] > 0 || v[i][j] > 0)) {
        cout << "-1\n";
        return 0;
      }
    }
  cout << stars.size() << '\n';
  for (auto &x : stars)
    cout << x.first.first + 1 << ' ' << x.first.second + 1 << ' ' << x.second
         << '\n';
  return 0;
}