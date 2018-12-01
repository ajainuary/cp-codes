#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<bool> num(k, false);
  long long int a1;
  cin >> a1;
  long long int g = a1;
  long long int a;
  for (int i = 1; i < n; ++i) {
    cin >> a;
    g = __gcd(g, a);
  }
  long long int x = g;
  int d = 0;
  for (int i = 1; i <= k; ++i) {
    x = g * i;
    if (num[x % k] == false) {
      ++d;
      num[x % k] = true;
    }
  }
  cout << d << endl;
  for (int i = 0; i < k; ++i)
    if (num[i]) cout << i << ' ';
  cout << endl;
  return 0;
}