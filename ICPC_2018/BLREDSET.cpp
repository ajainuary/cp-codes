#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);
const unsigned long long int mod = (unsigned long long int)1e9 + 7;
unsigned long long int sum = 0, black = 0, red = 0;

void counting_dfs(int v, vector<vector<int>> &G, vector<int> &color,
                  vector<pair<int, int>> &count, vector<bool> &visited,
                  vector<bool> &state) {
  visited[v] = true;
  if (color[v] == 1)
    ++count[v].first;
  else if (color[v] == 2)
    ++count[v].second;
  for (int &x : G[v])
    if (!visited[x]) {
      counting_dfs(x, G, color, count, visited, state);
      count[v].first += count[x].first;
      count[v].second += count[x].second;
      if (color[v] == 0) {
        if ((count[x].first != 0 && count[x].second != red) ||
            (count[x].first != black && count[x].second != 0)) {
          state[v] = true;
        }
      }
    }
  return;
}

void dfs(int v, vector<vector<int>> &G, vector<int> &color,
         vector<pair<unsigned long long int, unsigned long long int>> &ans,
         vector<bool> &visited, vector<bool> &state) {
  visited[v] = true;
  unsigned long long int all = 1, invalid = 1;
  for (int &x : G[v]) {
    if (!visited[x]) {
      dfs(x, G, color, ans, visited, state);
      if (color[v] == 0) {
        all = (all * (((ans[x].first + ans[x].second) % mod + 1) % mod)) % mod;
        invalid = (invalid * (ans[x].second + 1)) % mod;
      }
    }
  }
  if (color[v] == 0) {
    if (state[v]) {
      ans[v] = {all, 0};
      sum = (sum + all) % mod;
    } else {
      ans[v] = {(all + (mod - invalid)) % mod, invalid};
      sum = (sum + ans[v].first) % mod;
    }
  }
  return;
}

int main() {
  FAST_IO
  int t;
  cin >> t;
  while (t--) {
    sum = 0, black = 0, red = 0;
    int n;
    cin >> n;
    vector<vector<int>> G(n + 1);
    for (int i = 1, u, v; i < n; ++i) {
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    vector<int> color(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> color[i];
      if (color[i] == 1)
        ++black;
      else if (color[i] == 2)
        ++red;
    }
    vector<pair<int, int>> count(n + 1,
                                 {0, 0});  // first: black (1), second: red (2)
    vector<bool> visited(n + 1, false);
    vector<bool> state(n + 1, false);
    counting_dfs(1, G, color, count, visited, state);
    for (int i = 0; i <= n; ++i) visited[i] = false;
    vector<pair<unsigned long long int, unsigned long long int>> ans(
        n + 1, {0, 0});  // first: valid, second: invalid
    dfs(1, G, color, ans, visited, state);
    cout << sum << '\n';
  }
  return 0;
}