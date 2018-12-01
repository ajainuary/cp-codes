#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1000000007;

vector<vector<long long int>> cache(5000, vector<long long int>(2500, -1));

long long int powm(long long int a, long long int b) {
  long long int ans = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      ans = (ans * a) % MOD;
      b--;
    }
    a = (a * a) % MOD;
    b = b / 2;
  }
  return ans;
}

long long int C(long long int n, long long int r) {
  if (n < r) return 0;
  if (r > n - r) r = n - r;
  if (r == 0) return 1;
  if (r == 1) return n;
  if (cache[n][r] != -1) return cache[n][r];
  cache[n][r] = (C(n - 1, r) + C(n - 1, r - 1)) % (MOD - 1);
  return cache[n][r];
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<long long int> A(n);
    for (long long int &x : A) cin >> x;
    sort(A.begin(), A.end());
    long long int ans = 1;
    long long int sum = 0;
    for (int i = 0; i < n; ++i) {
      long long int binomial =
          ((MOD - 1 +
            ((MOD - 1 + C(n - 1, k - 1)) - C(n - i - 1, k - 1)) % (MOD - 1)) -
           C(i, k - 1)) %
          (MOD - 1);
      ans = (ans * powm(A[i], binomial)) % MOD;
    }
    cout << ans << endl;
  }
  return 0;
}