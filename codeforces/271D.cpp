#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, bad;
  cin >> s;
  cin >> bad;
  int k;
  cin >> k;
  int n = s.length();
  vector<int> z(n, 0);
  int ans = 0;
  for (int j = n - 1; j >= 0; --j) {
    int zmax = 0;
    for (int i = j + 1, l = j, r = j; i < n; ++i) {
      if (i <= r) z[i] = min(z[i - l + j], r - i + 1);
      while (i + z[i] < n && s[z[i] + j] == s[z[i] + i]) ++z[i];
      if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
      if (z[i] > zmax) zmax = z[i];
    }
    int v = 0;
    for (int i = j; i < n; ++i) {
      if (bad[s[i] - 'a'] == '0') ++v;
      if (v > k) break;
      if (i - j > zmax - 1) ++ans;
    }
    for (int i = j; i < n; ++i) z[i] = 0;
  }
  cout << ans << '\n';
  return 0;
}