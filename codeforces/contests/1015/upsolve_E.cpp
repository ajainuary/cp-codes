#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  vector<vector<bool>> visit(n, vector<bool>(m, false));
  vector<pair<pair<int, int>, int>> star;
  for (auto &x : grid) cin >> x;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] != '*') continue;
      int s = 1;
      while (i + s < n && i - s >= 0 && j + s < m && j - s >= 0 &&
             grid[i + s][j] == '*' && grid[i - s][j] == '*' &&
             grid[i][j + s] == '*' && grid[i][j - s] == '*') {
        visit[i + s][j] = true;
        visit[i - s][j] = true;
        visit[i][j + s] = true;
        visit[i][j - s] = true;
        ++s;
      }
      if (s > 1) {
        visit[i][j] = true;
        star.push_back({{i+1, j+1}, s - 1});
      }
    }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (grid[i][j] == '*' && visit[i][j] == false) {
        cout << "-1\n";
        return 0;
      }
  cout << star.size() << '\n';
  for (auto &x : star)
    cout << x.first.first << ' ' << x.first.second << ' ' << x.second << '\n';
  return 0;
}