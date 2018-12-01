#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a[0];
  int gcd = a[0];
  int max_a = INT_MIN;
  for (int i = 1; i < n; ++i) {
    cin >> a[i];
    gcd = __gcd(a[i], gcd);
    if (a[i] > max_a) max_a = a[i];
  }
  for (int &x : a) x /= gcd;
  // Sieve with complexity nlog(n)
  vector<int> lowest_prime_factor(max_a + 1, -1);
  for (int i = 2; i <= max_a; ++i)
    if (lowest_prime_factor[i] == -1)
      for (int j = 1; j * i <= max_a; ++j) lowest_prime_factor[j * i] = i;
  // Prime factorization
  vector<pair<int, int>> freq_prime_occurence(max_a + 1, {0, -1});
  for (int i = 0; i < n; ++i)
    while (a[i] != 1) {
      if (freq_prime_occurence[lowest_prime_factor[a[i]]].second < i) {
        ++freq_prime_occurence[lowest_prime_factor[a[i]]].first;
        freq_prime_occurence[lowest_prime_factor[a[i]]].second = i;
      }
      a[i] /= lowest_prime_factor[a[i]];
    }
  int max_freq = 0;
  for (int i = 2; i < max_a; ++i) {
    if (freq_prime_occurence[i].first > max_freq)
      max_freq = freq_prime_occurence[i].first;
  }
  if (max_freq != 0)
    cout << n - max_freq << '\n';
  else
    cout << -1 << '\n';
  return 0;
}