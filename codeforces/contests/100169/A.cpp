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
  int n, m, p;
  cin >> n >> m >> p;
  vector<vector<pair<int, pair<int, int>>>> G(n);
  for (int i = 0, a, b, c; i < m; ++i) {
    char t;
    cin >> a >> b >> c >> t;
    G[a].push_back({b, {(t == 'I') ? 0 : 1, c}});
    G[b].push_back({a, {(t == 'I') ? 0 : 1, c}});
  }
  for (int i = 0, a, b; i < p; ++i) {
    cin >> a >> b;
    vector<bool> visited(n, false);
    vector<pair<int, int>> dist(n, {INT_MAX, INT_MAX});
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>,
                   greater<pair<pair<int, int>, int>>>
        Q;
    dist[a] = {0,0};
    Q.push({{0, 0}, a});
    while (!Q.empty() && !visited[b]) {
      auto cur = Q.top();
      // cerr << cur.second << '\n';
      Q.pop();
      if(!visited[cur.second])
      {
      	visited[cur.second] = true;
      	for(auto &x : G[cur.second])
      	{
      		pair <int, int> e = x.second;
      		pair <int, int> d = cur.first;
      		if(e.first == 1)
      			d.first += e.second;
      		else
      			d.second += e.second;
      		if(d < dist[x.first])
      		{
      			dist[x.first] = d;
      			Q.push({d, x.first});
      		}
      	}
      }
    }
    if(!visited[b])
    	cout << "IMPOSSIBLE\n";
    else
    	cout << dist[b].first << ' ' << dist[b].second << '\n';	
  }
  return 0;
}