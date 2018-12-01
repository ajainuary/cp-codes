#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define sz(a) ll(a.size())
#define dbg(x) \
  { cerr << #x << " = " << x << endl; }

vector<vector<vector<int>>> cache(101,
                                  vector<vector<int>>(101,
                                                      vector<int>(101, -1)));

int dp(vector<int> &f, int i, int j, int n) {
  if (f[i] == 0 && n > 0) return INT_MIN;
  if (n == 0 || j > n) return INT_MAX;
  if (cache[i][j][n] == -1)
    cache[i][j][n] = max(min(dp(f, i + 1, 1, n - j), f[i] / j),
                         min(dp(f, i, j + 1, n), f[i] / (j + 1)));
  return cache[i][j][n];
}

int main() {
  FAST_IO
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  vector<int> f(101, 0);
  for (int &x : a) {
    cin >> x;
    ++f[x];
  }
  sort(f.rbegin(), f.rend());
  cout << dp(f, 0, 1, n) << endl;
  return 0;
}