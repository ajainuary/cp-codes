#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);

int main() {
  FAST_IO
  long long int n, m;
  cin >> n >> m;
  vector<pair<long long int, long long int>> graph(m);
  int e = 0;
  for (int i = 1; i < n && e < m; ++i)
    for (int j = i + 1; j <= n && e < m; ++j)
      if (__gcd(j, i) == 1) graph[e++] = {i, j};
  if (e < m || m < n-1)
    cout << "Impossible\n";
  else {
    cout << "Possible\n";
    for (auto &x : graph) cout << x.first << ' ' << x.second << '\n';
  }
  return 0;
}