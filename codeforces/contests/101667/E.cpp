#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define sz(a) ll(a.size())
#define dbg(x) \
  { cerr << #x << " = " << x << endl; }

int dsu_find(vector <int> &component, int v) {
  if (component[v] < 0) return v;
  component[v] = dsu_find(component, component[v]);
  return component[v];
}

void dsu_join(vector<int> &component, int v, int u) {
  int parent_v = dsu_find(component, v);
  int parent_u = dsu_find(component, u);
  if (component[parent_v] > component[parent_u])
    component[parent_v] = parent_u;
  else if (component[parent_u] > component[parent_v])
    component[parent_u] = parent_v;
  else {
    component[parent_u] = parent_v;
    --component[parent_v];
  }
  return;
}

int main() {
  FAST_IO
  /*   DON'T USE SCANF or PRINTF NOW!   */
  int n, m;
  cin >> n >> m;
  vector<pair<int, pair<int, int>>> edge(m);
  vector<bool> visited(m, false);
  vector<int> happy(m, 0);
  for (auto &x : edge) cin >> x.second.first >> x.second.second >> x.first;
  sort(edge.begin(), edge.end());
  for (int i = 0, max_happy = m; i < max_happy; ++i) {
  	dsu_join()
    vector<int> component(n, -1);
    for (int j = i; j < m; ++j) {
      auto x = edge[j];
      if (dsu_find(component, x.second.first) !=
          dsu_find(component, x.second.second)) {
        dsu_join(component, x.second.first, x.second.second);
        if (!visited[j]) {visited[j] = true; happy[i] = i;
        	dbg(i);
        	dbg(happy[i])}
      }
    }
  }
  int sum_happy = 0;
  for (auto &x : happy) sum_happy += x;
  cout << sum_happy << endl;
  return 0;
}