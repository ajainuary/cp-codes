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
  unsigned long long int b;
  cin >> b;
  unsigned long long int ans = 1;
  for (unsigned long long int i = 2; i <= sqrt(b); ++i) {
    unsigned long long int k = 0;
    while (b % i == 0) {
      ++k;
      b /= i;
    }
    ans *= k + 1;
  }
  if (b >= 2) {
    ans *= 2;
  }
  cout << ans << endl;
  return 0;
}