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
  long long int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int gcd = a[0];
  int max = a[0];
  for (int i = 1; i < n; ++i) {
    gcd = __gcd(a[i], gcd);
    if (a[i] > max) max = a[i];
  }
  for (int i = 0; i < n; ++i) {
    a[i] = a[i] / gcd;
  }
  
  return 0;
}