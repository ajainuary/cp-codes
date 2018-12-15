#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);

int main() {
  FAST_IO
  int n, m;
  cin >> n >> m;
  vector<int> col(n), row;
  for (int &x : col) cin >> x;
  for (int i = 0, x1, x2, y; i < m; ++i) {
    cin >> x1 >> x2 >> y;
    if (x1 == 1) row.push_back(x2);
  }
  col.push_back(1000000000);
  sort(col.begin(), col.end());
  sort(row.begin(), row.end());
  int min_spell = INT_MAX, spell = distance(lower_bound(row.begin(), row.end(), 1000000000), row.end());
  for (int i = n - 1; i >= 0; --i) {
    min_spell = min(min_spell, i + spell + 1);
    spell += distance(lower_bound(row.begin(), row.end(), col[i]),
                      lower_bound(row.begin(), row.end(), col[i + 1]));
  }
  min_spell = min(min_spell, spell);
  cout << min_spell << endl;
  return 0;
}