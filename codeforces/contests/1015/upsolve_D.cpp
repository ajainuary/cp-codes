#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int n, k, s;
  cin >> n >> k >> s;
  if (k > s || k * (n - 1) < s) {
    cout << "NO\n";
    return 0;
  } else
    cout << "YES\n";
  int h = 1;
  while (k > 0 && s - n + 2 >= k) {
    s -= n - 1;
    if (h == 1) {
      cout << n << ' ';
      h = n;
    } else {
      cout << 1 << ' ';
      h = 1;
    }
    --k;
  }
  int diff = (h == 1) ? 1 : -1;
  for (int i = 1; i < k; ++i, --s) {
    if ((i & 1) == 0)
      h -= diff;
    else
      h += diff;
    cout << h << ' ';
  }
  if (s > 0) {
    if (h - s < 1)
      cout << h + s << endl;
    else
      cout << h - s << endl;
  }
  return 0;
}