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
  int n, m;
  cin >> n >> m;
  vector<long long int> a(n);
  for (long long int &x : a) cin >> x;
  long long int line = 0;
  for (int i = 0; i < n; ++i) {
    cout << (line + a[i]) / m << ' ';
    line = (line + a[i]) % m;
  }
  sort(queries.begin(), queries.end(), block_divider);
  
  return 0;
}