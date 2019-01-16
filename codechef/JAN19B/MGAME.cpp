#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);

int main() {
  FAST_IO
  int t;
  cin >> t;
  while (t--) {
    long long int n, p;
    cin >> n >> p;
    long long int x = n / 2;
    if (n % 2 == 0) --x;
    if(x == 0) cout << p*p*p << '\n';
    else cout << (p - x) * (p - x) + (p - n) * (p - x) + (p - n) * (p - n) << '\n';
  }
  return 0;
}