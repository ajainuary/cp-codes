#include <bits/stdc++.h>
using namespace std;
array<pair<long long int, long long int>, 26> d;
int main() {
  d[0] = {0, 1};
  d[1] = {1, 2};
  for (long long int i = 2, p, q, g; i < 26; ++i) {
    p = d[i - 1].first * d[i - 2].second + d[i - 2].first * d[i - 1].second;
    q = (d[i - 1].second * d[i - 2].second) << 1;
    g = __gcd(p, q);
    d[i] = {p / g, q / g};
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << d[n].first << ' ' << d[n].second << ' ';
  }
  return 0;
}