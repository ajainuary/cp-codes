#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);

void Update(vector<pair<long long int, long long int>> &tree, long long int s, long long int e,
            long long int v, int i, long long int l, long long int r) {
  // cerr << l << ' ' << r << endl;
  if (e < l || r < s) return;
  if (s <= l && r <= e) {
    // cerr << "Updated " << l << ' ' << r << endl;
    tree[i].second += v;
    return;
  }
  int mid = (l + r) >> 1;
  int left = (i << 1) | 1;
  int right = left + 1;
  Update(tree, s, e, v, left, l, mid);
  Update(tree, s, e, v, right, mid + 1, r);
  tree[i].first += (min(e, r) - max(s, l) + 1) * v;
  return;
}

long long int Query(vector<pair<long long int, long long int>> &tree, int s,
                    int e, int i, long long int l, long long int r) {
  int mid = (l + r) >> 1;
  int left = (i << 1) | 1;
  int right = left + 1;
  tree[i].first += tree[i].second * (r - l + 1);
  if (l != r) {
    tree[left].second += tree[i].second;
    tree[right].second += tree[i].second;
  }
  tree[i].second = 0;
  if (e < l || r < s) return 0;
  if (s <= l && r <= e) return tree[i].first;
  return Query(tree, s, e, left, l, mid) + Query(tree, s, e, right, mid + 1, r);
}

int main() {
  FAST_IO
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<long long int, long long int>> tree((n << 2) + 1, {0, 0});
    int c;
    cin >> c;
    for (long long int i = 0, k, p, q, v; i < c; ++i) {
      cin >> k;
      if (k == 0) {
        cin >> p >> q >> v;
        Update(tree, p - 1, q - 1, v, 0, 0, n - 1);
      } else {
        cin >> p >> q;
        cout << Query(tree, p - 1, q - 1, 0, 0, n - 1) << endl;
      }
      // for (int i = 0; i < n << 2; ++i) {
      //   cout << "i = " << i << ' ' << tree[i].first << ' ' << tree[i].second
      //        << endl;
      // }
    }
  }
  return 0;
}