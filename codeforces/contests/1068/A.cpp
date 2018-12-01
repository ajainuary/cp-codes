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
  long double n, m, k, l;
  cin >> n >> m >> k >> l;
  if (l == 0)
    cout << 0 << endl;
  else if (n < ceil((k + l) / m) * m)
    cout << -1 << endl;
  else
    cout << (unsigned long long int)ceil((k + l) / m) << endl;
  return 0;
}