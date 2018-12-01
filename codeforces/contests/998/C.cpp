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
  long long int n, x, y;
  cin >> n >> x >> y;
  string a;
  cin >> a;
  long long int one = 0;
  long long int zero = 0;
  int cur = 2;
  for (int i = 0; i < a.length(); ++i) {
    if (cur != a[i] - '0') {
      cur = a[i] - '0';
      if (cur == 0)
        ++zero;
      else
        ++one;
    }
  }

  long long int cost = 0;
  while (zero > 1) {
    if (zero * (y - 1) > (zero - 1) * x) {
      --zero;
      cost += x;
    } else {
      --zero;
      cost += y;
    }
  }
  if (zero > 0) cost += y;
  cout << cost << endl;
  return 0;
}