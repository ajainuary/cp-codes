#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    n--, m--;
    if ((n % x == 0 && m % y == 0) || (((x == 1 && n != 0) || n % x == 1) &&
                                       ((y == 1 && m != 0) || m % y == 1)))
      cout << "Chefirnemo" << '\n';
    else
      cout << "Pofik" << '\n';
  }
  return 0;
}