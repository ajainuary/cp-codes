#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);

int main() {
  FAST_IO
  int t;
  cin >> t;
  while (t--) {
    int n, a, n_a = 0, b, n_b = 0, n_c = 0;
    cin >> n >> a >> b;
    for (int i = 0, x; i < n; ++i) {
      cin >> x;
      if(x % a == 0 && x % b == 0) ++n_c;
      else if (x % a == 0) ++n_b;
      else if (x % b == 0) ++n_a;
    }
    if (a == b || (n_c != 0 && n_a <= n_b) || (n_c == 0 && n_a < n_b))
      cout << "BOB\n";
    else
      cout << "ALICE\n";
  }
  return 0;
}