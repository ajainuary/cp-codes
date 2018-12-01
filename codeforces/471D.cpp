#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, w;
  cin >> n >> w;
  vector<int> s(n + w + 1);
  s[w] = INT_MIN >> 1;
  ;
  for (int i = 0; i < n; ++i) cin >> s[w + i + 1];
  for (int i = 0; i < w; ++i) cin >> s[i];
  for (int i = w - 1; i >= 0; --i) s[i] -= s[0];
  vector<int> z(n + w + 1, 0);
  int see = 0;
  for (int i = 1, l = 0, r = 0; i < n + w + 1; ++i) {
    if (i <= r) z[i] = min(z[i - l], r - i + 1);
    while (i + z[i] < n + w + 1 && s[z[i]] == s[z[i] + i] - s[i]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    if (z[i] == w) ++see;
  }
  cout << ((w > 1) ? see : n) << '\n';
  return 0;
}