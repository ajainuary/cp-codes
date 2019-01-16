#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define DEBUG
#ifdef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
#else
#define debug(...)
#endif
#define trace(c, x) for (auto& x : c)

pair<int, int> dfs(int v, vector<pair<bool, int>>& visited, int color,
                   vector<vector<int>>& G) {
  if (visited[v].first) {
    if (visited[v].second == color)
      return {0, 0};
    else
      return {-1, -1};
  }
  visited[v] = {true, color};
  pair<int, int> n = {0, 0};
  if (color == 0)
    n.first = 1;
  else
    n.second = 1;
  for (auto& x : G[v]) {
    auto t = dfs(x, visited, 1 - color, G);
    if (t.first == -1) return {-1, -1};
    n.first += t.first, n.second += t.second;
  }
  return n;
}

long long int powm(long long int a, long long int b, long long int m) {
  long long int ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return ans;
}

int main() {
  FAST_IO
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n + 1);
    for (int i = 0, u, v; i < m; ++i) {
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    vector<pair<bool, int>> visited(n + 1, {false, 0});
    unsigned long long int ans = 1;
    for (int i = 1; i <= n; ++i) {
      if (!visited[i].first) {
        auto t = dfs(i, visited, 0, G);
        if (t.first != -1) {
          ans = (ans *
                 (powm(2, t.first, 998244353) + powm(2, t.second, 998244353)) %
                 998244353) %
                998244353;
        } else
          ans = 0;
      }
    }
    cout << ans << endl;
  }
  return 0;
}