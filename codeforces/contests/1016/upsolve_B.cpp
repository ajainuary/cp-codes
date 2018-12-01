#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  string p, r;
  cin >> p;
  cin >> r;
  string s = r + "#" + p;

  vector<int> z(n + m + 1, 0);
  for (int i = 1, l = 0, r = 0; i < n + m + 1; ++i) {
    if (i <= r) z[i] = min(z[i - l], r - i + 1);
    while (i + z[i] < n + m + 1 && s[z[i]] == s[z[i] + i]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  for (int i = 0; i < n + m + 1; ++i) cerr << i << ' ' << z[i] << endl;
  array<int, 1005> pfx_occ;
  for (int i = 0, occ = 0; i < n; pfx_occ[i++] = occ)
    if (z[i + m + 1] == m) ++occ;
  for (int i = 0, a, b; i < q; ++i) {
    cin >> a >> b;
    if (b - a >= m - 2)
      cout << ((b >= m) ? pfx_occ[b - m] : 0) - ((a > 1) ? pfx_occ[a - 2] : 0)
           << '\n';
    else
      cout << 0 << '\n';
  }
  return 0;
}