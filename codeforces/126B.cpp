#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) z[i] = min(z[i - l], r - i + 1);
    while (i + z[i] < n && s[z[i]] == s[z[i] + i]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  int max = 0;
  int maxz = 0;
  int maxi = 0;
  for (int i = 1; i < n; ++i)
    if (z[i] > maxz) maxz = z[i], maxi = i;
  for (int i = 1; i <= maxz; ++i)
    if (z[n - i] == i && z[n - i] > max && n - i != maxi) max = z[n - i];
  if (max == 0)
    cout << "Just a legend\n";
  else {
    for (int i = 0; i < max; ++i) cout << s[i];
    cout << '\n';
  }

  return 0;
}