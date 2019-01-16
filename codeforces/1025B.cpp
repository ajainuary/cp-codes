#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);

unsigned long long int gcd(unsigned long long int a, unsigned long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  FAST_IO
  int n;
  cin >> n;
  unsigned long long int g = 0;
  for (unsigned long long int i = 0, a, b; i < n; ++i) {
    cin >> a >> b;
    g = __gcd(g, a * b);
  }
  for (int i = 2; i < 44723; i++) {
    if (g % i == 0) {
      cout << i << endl;
      return 0;
    }
  }
  if (g != 1)
    cout << g << endl;
  else
    cout << -1 << endl;
  return 0;
}