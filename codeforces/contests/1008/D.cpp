#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define dbg(x) \
  { cerr << #x << " = " << x << endl; }

int main() {
  FAST_IO
  vector<vector<int>> factor(1e5 + 1);
  for (int i = 1; i <= 1e5; ++i)
    for (int j = 1; j * i <= 1e5; ++j) factor[j * i].push_back(i);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    vector<pair<int, pair<int, int>>> sol;
    for (int &x : factor[a])
      for (int &y : factor[b])
        for (int &z : factor[c]) sol.push_back({x, {y, z}});
    sort(sol.begin(), sol.end());
  	long long int k = 0;
    for (auto i = sol.begin(); i != sol.end(); ++i)
      if ((i + 1) != sol.end() || *i != *(i + 1))
        ++k;
    cout << k << '\n';
  }
  return 0;
}