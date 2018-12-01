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
  vector<int> l(n);
  vector<int> r(n);
  for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];
  sort(l.begin(), l.end());
  sort(r.begin(), r.end());
  int i = 1;
  int j = 0;
  int prev = l[0];
  vector<int> ans(n + 1);
  int stage = 1;
  while (i < n || j < n) {
  	dbg(i)
  	dbg(j)
    if (j >= n || l[i] < r[j]) {
      ans[stage] += l[i] - prev;
      prev = l[i];
      ++stage;
      ++i;
    } else if (i >= n || l[i] > r[j]) {
      ans[stage] += r[j] - prev + 1;
      prev = r[j];
      --stage;
      ++j;
    } else {
      --stage;
      ++j;
    }
  }
  for (int k = 1; k <= n; ++k) {
    cout << ans[k] << ' ';
  }
  cout << endl;
  return 0;
}