#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define sz(a) ll(a.size())
#define dbg(x) \
  { cerr << #x << " = " << x << endl; }

long long int dist(int x1, int y1, int x2, int y2, vector<int> &l,
                   vector<int> &e, int v) {
  int yless = min(y1, y2);
  int ymore = max(y1, y2);
  auto l1u = lower_bound(l.begin(), l.end(), yless);
  auto l2u = lower_bound(l.begin(), l.end(), yless, greater<int>());
  int l1 = (l1u == l.end()) ? INT_MAX / 4 : *l1u;
  int l2 = (l2u == l.end()) ? INT_MAX / 4 : *l2u;
  int ladder = min(abs(l1 - yless) + abs(x1 - x2) + abs(ymore - l1),
                   abs(yless - l2) + abs(x1 - x2) + abs(ymore - l2));
  if (l1u == l.end()) {
    ladder = abs(yless - l2) + abs(x1 - x2) + abs(ymore - l2);
  }
  if (l2u == l.end()) {
    ladder = abs(yless - l2) + abs(x1 - x2) + abs(ymore - l2);
  }
  if (l1u == l.end() && l2u == l.end()) {
    ladder = INT_MAX;
  }
  auto e1u = lower_bound(e.begin(), e.end(), yless);
  auto e2u = lower_bound(e.begin(), e.end(), yless, greater<int>());
  int e1 = (e1u == e.end()) ? INT_MAX / 4 : *e1u;
  int e2 = (e2u == e.end()) ? INT_MAX / 4 : *e2u;
  int elevator =
      min(abs(e1 - yless) +
              ((abs(x1 - x2) / v) + ((abs(x1 - x2) % v == 0) ? 0 : 1)) +
              abs(ymore - e1),
          abs(yless - e2) +
              ((abs(x1 - x2) / v) + ((abs(x1 - x2) % v == 0) ? 0 : 1)) +
              abs(e2 - ymore));
  if (e1u == e.end()) {
    elevator = abs(yless - e2) +
               ((abs(x1 - x2) / v) + ((abs(x1 - x2) % v == 0) ? 0 : 1)) +
               abs(e2 - ymore);
  }
  if (e2u == e.end()) {
    elevator = abs(e1 - yless) +
               ((abs(x1 - x2) / v) + ((abs(x1 - x2) % v == 0) ? 0 : 1)) +
               abs(ymore - e1);
  }
  if (e1u == e.end() && e2u == e.end()) {
    elevator = INT_MAX;
  }
  return min(ladder, elevator);
}

int main() {
  FAST_IO
  int n, m, cl, ce, v;
  cin >> n >> m >> cl >> ce >> v;
  vector<int> l(cl);
  vector<int> e(ce);
  for (int &x : l) cin >> x;
  for (int &x : e) cin >> x;
  int q;
  cin >> q;
  for (int i = 0, x1, x2, y1, y2; i < q; ++i) {
    cin >> x1 >> y1 >> x2 >> y2;
    cout << dist(x1, y1, x2, y2, l, e, v) << '\n';
  }
  return 0;
}