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
  int n, s;
  cin >> n >> s;
  vector<int> l(n);
  for (int i = 0, h, s; i < n; ++i) {
    cin >> h >> s;
    l[i] = (h * 60) + s;
  }
  int cur = -s - 1;
  int next = 0;
  for (int i = 0; i < n; ++i) {
    next = l[i];
    if (next - cur > (2 * s) + 1) {
      cout << (cur + s + 1) / 60 << ' ' << (cur + s + 1) % 60 << endl;
      return 0;
    }
    cur = next;
  }
  cout << (cur + s + 1) / 60 << ' ' << (cur + s + 1) % 60 << endl;
  return 0;
}