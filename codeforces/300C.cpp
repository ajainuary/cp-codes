#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
bool isGood(int x, int a, int b) {
  while (x > 0) {
    if (x % 10 != a && x % 10 != b) return false;
    x /= 10;
  }
  return true;
}

long long int powm(long long int a, long long int b, long long int m) {
  long long int ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return ans;
}

int main() {
  long long int a, b, n;
  cin >> a >> b >> n;
  vector<long long int> ncr(n + 1);
  ncr[0] = 1;
  for (int i = 1; i <= n; ++i) {
    ncr[i] = (ncr[i - 1] * (n - i + 1)) % mod;
    ncr[i] = (ncr[i] * powm(i, mod - 2, mod)) % mod;
  }
  long long int ans = 0;
  for (int i = 0; i <= n; ++i) {
    if (isGood(a * i + b * (n - i), a, b)) {
      ans = (ans + ncr[i]) % mod;
    }
  }
  cout << ans << '\n';
  return 0;
}