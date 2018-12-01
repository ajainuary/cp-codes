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
  int x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  if (abs(z - x) * t2 + abs(x - y) * t2 + 3 * t3 <= abs(x - y) * t1)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}