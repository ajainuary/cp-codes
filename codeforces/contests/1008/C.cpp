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
  cin>>n;
  vector<int> a(n);
  map<int, int> f;
  for (int &x : a) {
    cin >> x;
    if (f.count(x) == 1)
      ++f[x];
    else
      f[x] = 1;
  }
  int perm = 0;
  for (int &x : a) {
    auto y = f.upper_bound(x);
    if (y != f.end()) {
      ++perm;
      --y->second;
      if (y->second == 0) f.erase(y);
    }
  }
  cout << perm << endl;
  return 0;
}