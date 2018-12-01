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
  int n;
  cin >> n;

  for (int i = (n >> 1)+1; i <= n; ++i) {
    cout << i << ' ';
  }
  for (int i = 1; i < (n >> 1) + 1; ++i) {
    cout << i << ' ';
  }
  cout << endl;
  return 0;
}