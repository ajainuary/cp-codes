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
  int len;
  cin >> len;
  string tmp;
  cin >> tmp;
  string tmp2 = tmp;
  reverse(tmp2.begin(), tmp2.end());
  string s = tmp + tmp + tmp2 + tmp2;
  int n = len << 2;
  vector<int> z(n, 0);
  long long int ans = 0;
  for (int j = n - 1; j >= 0; --j) {
    int zmax = 0;
    for (int i = j + 1, l = j, r = j; i < n; ++i) {
      if (i <= r) z[i] = min(z[i - l + j], r - i + 1);
      while (i + z[i] < n && s[z[i] + j] == s[z[i] + i]) ++z[i];
      if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
      if (z[i] > zmax) zmax = z[i];
    }
    // dbg(j)
    // dbg(zmax)
    int k = j + zmax;
    if (!(k - j > len - 1 || (k >= 2 * len && j < 2 * len))) {
      if (j < (len<<1)) {
        // cerr<<"c"<<endl;
        // dbg(k)
        // dbg(j)
        // dbg(min((2*len), j+len)-k)
        ans += min((len<<1), j + len) - k;
      } else {
        // cerr<<"ac"<<endl;
        // dbg(k)
        // dbg(j)
        // dbg(min(n, j+len)-k)
        ans += min(n, j + len) - k;
      }
    }
    // for (int i = j + zmax; i < n; ++i) {
    //   if (i - j > len - 1 || (i >= 2*len && j < 2*len)) break;
    //   if (i - j > zmax - 1) ++ans;
    // }
    for (int i = j; i < n; ++i) z[i] = 0;
  }
  cout << ans << '\n';
  return 0;
}