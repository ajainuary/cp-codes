#include <bits/stdc++.h>
using namespace std;
#define sz(a) ll(a.size())
#define dbg(x) \
  { cerr << #x << " = " << x << endl; }

int main() {
  int m, n;
  cin >> m >> n;
  vector<bool> p(n);
  for (int i = 0, out; i < n; ++i) {
    cout << m << endl;
    cin >> out;
    if (out == 0 || out == -2)
      return 0;
    else if (out > 0)
      p[i] = false;
    else
      p[i] = true;
  }
  int l = 1;
  int r = m;
  int out;
  int i = 0;
  do {
    int mid = (l + r) >> 1;
    cout << mid << endl;
    cin >> out;
    if (out == -2) return 0;
    if (out > 0) {
      if (p[i % n])
        l = mid + 1;
      else
        r = mid - 1;
    } else {
      if (p[i % n])
        r = mid - 1;
      else
        l = mid + 1;
    }
    ++i;
  } while (out != 0);
  return 0;
}