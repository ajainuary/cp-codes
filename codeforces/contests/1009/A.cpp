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
  int n, m;
  cin >> n >> m;
  vector<int> c(n);
  for (int &x : c) cin >> x;
  vector<int> a(m);
  for (int &x : a) cin >> x;
  int i = 0;
  int j = 0;
  int buy = 0;
  while (i < n && j < m) {
    if (c[i] <= a[j]) {
      ++i;
      ++j;
      ++buy;
    } else
      ++i;
  }
  cout << buy << endl;
  return 0;
}