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
  int n, M;
  cin >> n >> M;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  vector<int> lit(n + 2);
  vector<int> unlit(n + 2);
  lit[0] = 0;
  unlit[0] = 0;
  lit[1] = a[0];
  unlit[1] = 0;
  int state = 0;
  for (int i = 1; i < n; ++i) {
    lit[i + 1] = lit[i] + state * (a[i] - a[i - 1]);
    unlit[i + 1] = unlit[i] + (1 - state) * (a[i] - a[i - 1]);
    state = 1 - state;
  }
  lit[n + 1] = lit[n] + state * (M - a[n - 1]);
  unlit[n + 1] = unlit[n] + (1 - state) * (M - a[n - 1]);
  int more = INT_MIN + 1;
  for (int i = 0; i < n; ++i) {
    if (unlit[n + 1] - unlit[i + 1] - (lit[n + 1] - lit[i + 1]) > more - 1) {
      more = unlit[n + 1] - unlit[i + 1] - (lit[n + 1] - lit[i + 1]);
    }
  }
  if (more > 0)
    cout << more + lit[n + 1] - 1 << endl;
  else
    cout << lit[n + 1] << endl;
  return 0;
}