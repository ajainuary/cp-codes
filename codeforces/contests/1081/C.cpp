#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define DEBUG
#ifdef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
#else
#define debug(...)
#endif
#define trace(c, x) for (auto& x : c)

array<array<long long int, 2000>, 2000> cache;
long long int c(int n, int r) {
  if (n - r < r) return c(n, n - r);
  if (cache[n][r] != 0) return cache[n][r];
  if(r == 0) return 1;
  if(r == 1) return n;
  cache[n][r] = (c(n - 1, r) + c(n - 1, r - 1)) % 998244353;
  return cache[n][r];
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
  FAST_IO
  long long int n, m, k;
  cin >> n >> m >> k;
  long long int ans =
      (((c(n - 1, k) * m) % 998244353) * powm(m - 1, k, 998244353)) % 998244353;
  cout << ans << endl;
  return 0;
}