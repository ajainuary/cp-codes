#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    unsigned long long int sum = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) {
        if (x == i && y == j) continue;
        unsigned long long int not_pos = 0;
        if (j == y) {
          if (x < i)
            not_pos += n - x - 1;
          else
            not_pos += x - 2;
        } else
          not_pos += n - 1;
        if (i == x) {
          if (y < j)
            not_pos += m - y - 1;
          else
            not_pos += y - 2;
        } else
          not_pos += m - 1;
        if (abs(x - i) == abs(y - j)) {
          if (x < i && y < j)
            not_pos += min(i - x, j - y) + min(i - 1, m - j) +
                       min(n - i, j - 1) + min(n - i, m - j) - 1;
          else if (x < i && y > j)
            not_pos += min(i - 1, j - 1) + min(i - x, y - j) +
                       min(n - i, j - 1) + min(n - i, m - j) - 1;
          else if (x > i && y > j)
            not_pos += min(i - 1, j - 1) + min(i - 1, m - j) +
                       min(n - i, j - 1) + min(x - i, y - j) - 1;
          else
            not_pos += min(i - 1, j - 1) + min(i - 1, m - j) +
                       min(x - i, j - y) + min(n - i, m - j) - 1;
        } else
          not_pos += min(i - 1, j - 1) + min(i - 1, m - j) + min(n - i, j - 1) +
                     min(n - i, m - j);
        sum += n * m - not_pos - 2;
      }
    cout << sum << '\n';
  }
  return 0;
}