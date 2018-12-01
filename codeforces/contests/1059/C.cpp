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
  int n;
  cin >> n;
  int g = 1;
  cout << 1 << ' ';
  while (n != 1) {
    if (n == 3) {
      cout << g << ' ' << g * 3 << '\n';
      break;
    } else if (n == 2) {
      cout << (g << 1) << '\n';
      break;
    }
    for (int i = 1, t = ((n & 1) == 0) ? n >> 1 : (n >> 1) + 1; i < t; ++i) {
      cout << g << ' ';
    }
    cout << (g << 1) << ' ';
    g = g << 1;
    n = n >> 1;
  }
  return 0;
}