#include <bits/stdc++.h>
using namespace std;
#define dbg(x) \
  { cerr << #x << " = " << x << endl; }

int dfs(vector<vector<int>> &graph, int i, int parent, vector<int> &father,
        vector<int> &level, int l, vector<int> &children) {
  if (level[i] != -1) return 0;
  level[i] = l;
  father[i] = parent;
  for (int &x : graph[i])
    children[i] += dfs(graph, x, i, father, level, l + 1, children);
  return children[i];
}

int lca(vector<vector<int>> &P, vector<int> &level, int p,
                       int q) {
  if (level[p] < level[q]) swap(p, q);
  int log = floor(log2(level[p]));
  for (int i = log; i >= 0; --i)
    if (level[p] - (1 << i) >= level[q]) p = P[p][i];
  if(p == q)
    return p;
  for (int i = log; i >= 0; --i)
    if (P[p][i] != -1 && P[p][i] != P[q][i]) p = P[p][i], q = P[q][i];
  return P[p][0];
}

int ancestor(vector<vector<int>> &P, vector<int> &level, int p, int j) {
  int log = floor(log2(level[p]));
  for (int i = log; i >= 0 && j > 0; --i)
    if (P[p][i] != -1 && ((1 << i) & j) != 0) p = P[p][i];
  return p;
}

int main() {
  int n, m;
  cin >> n;
  vector<vector<int>> graph(n + 1);
  for (int i = 1, a, b; i < n; ++i) {
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  vector<int> father(n + 1);
  vector<int> children(n + 1, 1);
  vector<int> level(n + 1, -1);
  vector<vector<int>> P(n + 1, vector<int>(ceil(log2(n+1))+1  , -1));
  dfs(graph, 1, -1, father, level, 0, children);
  for (int i = 1; i <= n; ++i) P[i][0] = father[i];
  for (int j = 1; (1 << j) < n; ++j)
    for (int i = 1; i <= n; ++i)
      if (P[i][j - 1] != -1) P[i][j] = P[P[i][j - 1]][j - 1];
  cin >> m;
  for (int i = 0, x, y; i < m; ++i) {
    cin >> x >> y;
    if(x == y)
    {
      cout << n << endl;
      continue;
    }
    int lcaxy = lca(P, level, x, y);
    int dist = level[x] - level[lcaxy] + level[y] - level[lcaxy];
    if ((dist & 1) == 0) {
      int j = dist >> 1;
      int anx = ancestor(P, level, x, j - 1);
      int any = ancestor(P, level, y, j - 1);
      int loweran = (level[x] > level[y]) ? x : y;
      int lowerb = ancestor(P, level, loweran, j-1);
      int an = ancestor(P, level, loweran, j);
      // dbg(loweran)
      if (an == lcaxy) {
        // dbg(anx)
        // dbg(any)
        cout << n - children[anx] - children[any] << endl;
      } else {
        // dbg(an)
        // dbg(lowerb)
        cout << children[an] - children[lowerb] << endl;
      }
    } else {
      cout << 0 << endl;
    }
  }
  return 0;
}