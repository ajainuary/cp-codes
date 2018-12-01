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
  vector<bool> isPrime(15000001, true);
  for (int i = 2; i < 3873; ++i) {
    if (isPrime[i])
      for (int j = 0; (i + j) * i < 15000001; ++j) isPrime[(i + j) * i] = false;
  }
  int primes[970704];
  int k = 0;
  for (int i = 2; i < 15000001; ++i) {
    if (isPrime[i]) primes[k++] = i;
  }
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
  for (int i = 0; i < n; ++i)
  {
  	a[i] = a[i] / gcd;
  }
  int min = n;
  for (int j = 0; primes[j] <= max && min > 1 && j < 970704; ++j) {
    int fails = 0;
    if (gcd % primes[j] != 0) {
      for (int i = 0; fails < min && i < n; ++i) {
        if (a[i] % primes[j] != 0) ++fails;
      }
      min = fails;
    }
  }
  if (min == n)
    cout << -1 << '\n';
  else
    cout << min << '\n';
  return 0;
}