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
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> row(n);
  vector<vector<int>> col(m);
  queue<pair<int, int>> visit;
  for (int i = 0, r, c; i < q; ++i) {
    cin >> r >> c;
    visit.push({r, c});
  }
  return 0;
}