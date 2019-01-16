#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);
const int mod = 10000000007;
array<array<int, 101>, 101> C;
int nCr(int n, int r) {
  if (r > n) return 0;
  if (C[n][r] != 0) return C[n][r];
  C[n][r] = (nCr(n - 1, r) + nCr(n - 1, r - 1)) % mod;
  return C[n][r];
}
int main() {
  FAST_IO
  int t;
  cin >> t;
  while (t--) {
    vector<int> N(61, 0);
    int n;
    cin >> n;
    for (int i = 0, a; i < n; ++i) {
      cin >> a;
      ++N[a];
    }
    
  }
  return 0;
}