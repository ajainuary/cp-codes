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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int decreases = 0;
    for (int i = 1; i < n; ++i)
      if (a[i] < a[i - 1]) ++decreases;
    if (decreases == 0 || (decreases == 1 && a[0] >= a[n - 1]))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}