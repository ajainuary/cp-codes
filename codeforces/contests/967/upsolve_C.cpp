#include <bits/stdc++.h>
using namespace std;

int dist(int x1, int y1, int x2, int y2, vector<int> &l, vector<int> &e,
         int v) {
  if (x1 == x2) return abs(y2 - y1);
  int yless = min(y1, y2);
  int ymore = min(y1, y2);
  auto l1 = upper_bound(l.begin(), l.end(), yless);
  auto l2 = upper_bound(l.rbegin(), l.rend(), yless, greater<int>());
  int ladder;
  if (l1 != l.end() && l2 != l.rend())
    ladder = min(abs(*l1 - y1) + abs(x2 - x1) + abs(*l1 - y2),
                 abs(*l2 - y1) + abs(x2 - x1) + abs(*l2 - y2));
  else if (l1 != l.end())
    ladder = abs(*l1 - y1) + abs(x2 - x1) + abs(*l1 - y2);
  else if (l2 != l.rend())
    ladder = abs(*l2 - y1) + abs(x2 - x1) + abs(*l2 - y2);
  else
    ladder = INT_MAX;
  auto e1 = upper_bound(e.begin(), e.end(), yless);
  auto e2 = upper_bound(e.rbegin(), e.rend(), yless, greater<int>());
  int elevator;
  if (e1 != e.end() && e2 != e.rend())
    elevator = min(abs(*e1 - y1) + abs(x2 - x1) / v +
                       ((abs(x2 - x1) % v == 0) ? 0 : 1) + abs(*e1 - y2),
                   abs(*e2 - y1) + abs(x2 - x1) / v +
                       ((abs(x2 - x1) % v == 0) ? 0 : 1) + abs(*e2 - y2));
  else if (e1 != e.end())
    elevator = abs(*e1 - y1) + abs(x2 - x1) / v +
               ((abs(x2 - x1) % v == 0) ? 0 : 1) + abs(*e1 - y2);
  else if (e2 != e.rend())
    elevator = abs(*e2 - y1) + abs(x2 - x1) / v +
               ((abs(x2 - x1) % v == 0) ? 0 : 1) + abs(*e2 - y2);
  else
    elevator = INT_MAX;
  return min(ladder, elevator);
}

int main() {
  int n, m, cl, ce, v;
  cin >> n >> m >> cl >> ce >> v;
  vector<int> l(cl);
  for (int &x : l) cin >> x;
  vector<int> e(ce);
  for (int &x : e) cin >> x;
  int q;
  cin >> q;
  for (int i = 0, x1, x2, y1, y2; i < q; ++i) {
    cin >> x1 >> y1 >> x2 >> y2;
    cout << dist(x1, y1, x2, y2, l, e, v) << endl;
  }
  return 0;
}