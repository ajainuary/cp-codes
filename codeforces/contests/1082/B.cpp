#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define sz(a) ll(a.size())
#define dbg(x) \
  { cerr << #x << " = " << x << endl; }
array<array<array<int, 2>, 100005>, 2> cache = {0};
int dpF(string &s, int i, int w) {
  if (i == s.length()) return 0;
  if (cache[0][i][w] != 0) return cache[0][i][w];
  if (s[i] == 'G') {
    cache[0][i][w] = 1 + dpF(s, i + 1, w);
    return cache[0][i][w];
  }
  if (w == 0) return 0;
  cache[0][i][1] = 1 + dpF(s, i + 1, 0);
  return cache[0][i][1];
}

int dpR(string &s, int i, int w) {
  if (i == -1) return 0;
  if (cache[1][i][w] != 0) return cache[1][i][w];
  if (s[i] == 'G') {
    cache[1][i][w] = 1 + dpR(s, i - 1, w);
    return cache[1][i][w];
  }
  if (w == 0) return 0;
  cache[1][i][1] = 1 + dpR(s, i - 1, 0);
  return cache[1][i][1];
}

int main() {
  FAST_IO
  int n;
  cin >> n;
  string s;
  cin >> s;
  int max_len = 0;
  for (int i = 0, r = 0; i < n; ++i) {
    max_len = max(max_len, dpF(s, i, (r>0)?1:0));
    if (s[i] == 'G') ++r;
  }
  for (int i = n - 1, r = 0; i >= 0; --i) {
    max_len = max(max_len, dpR(s, i, (r>0)?1:0));
    if (s[i] == 'G') ++r;
  }
  cout << max_len << endl;
  return 0;
}