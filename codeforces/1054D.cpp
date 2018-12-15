#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);

int invert(int n, int k) {
  int xosr = 0;
  for (int i = 0; i < k; ++i) {
    xosr <<= 1;
    ++xosr;
  }
  n ^= xosr;
  return n;
}

int main() {
  FAST_IO
  long long int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  map<long long int, long long int> freq;
  freq.insert({0, 1});
  for (int i = 0, pfx = 0; i < n; ++i) {
    int pfx_tmp = pfx ^ a[i];
    auto t = freq.find(pfx_tmp);
    if (t == freq.end()) {
      freq.insert({pfx_tmp, 1});
      pfx = pfx_tmp;
    } else {
      int pfx_alt = pfx ^ invert(a[i], k);
      auto p = freq.find(pfx_alt);
      if (p == freq.end()) {
        freq.insert({pfx_alt, 1});
        pfx = pfx_tmp;
      } else if (p->second < t->second) {
        p->second++;
        pfx = pfx_alt;
      } else {
        t->second++;
        pfx = pfx_tmp;
      }
    }
  }
  long long int ans = ((n + 1) * n) >> 1;
  for (auto &x : freq) ans -= (x.second * (x.second - 1)) >> 1;
  cout << ans << '\n';
  return 0;
}