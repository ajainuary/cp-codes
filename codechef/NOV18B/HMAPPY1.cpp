#include <bits/stdc++.h>
using namespace std;

void build(vector<int> &seg_tree, vector<int> &a, int i, int s, int e,
           vector<int> &max_end, vector<int> &max_start) {
  if (s == e)
    seg_tree[i] = a[s];
  else {
    int mid = (s + e) >> 1;
    build(seg_tree, a, i << 1, s, mid, max_end, max_start);
    build(seg_tree, a, (i << 1) | 1, mid + 1, e, max_end, max_start);
    seg_tree[i] =
        max(max(seg_tree[(i << 1)], seg_tree[(i << 1) | 1]),
            min(max_end[mid], mid - s + 1) + min(max_start[mid + 1], e - mid));
  }
  return;
}

int lcs(vector<int> &seg_tree, int i, int s, int e, int p, int q,
        vector<int> &max_end, vector<int> &max_start) {
  if (q < s || e < p) return 0;
  if (p <= s && e <= q) return seg_tree[i];
  int mid = (s + e) >> 1;
  int left = lcs(seg_tree, i << 1, s, mid, p, q, max_end, max_start);
  int right = lcs(seg_tree, (i << 1) | 1, mid + 1, e, p, q, max_end, max_start);
  return max(max(left, right), min(max_end[mid], mid - max(s, p) + 1) +
                                   min(max_start[mid + 1], min(e, q) - mid));
}

int main() {
  int n, q, k;
  cin >> n >> q >> k;
  vector<int> a(n << 1);
  vector<int> max_end(n << 1);
  vector<int> max_start(n << 1);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) a[i + n] = a[i];
  for (int i = 0, i_max = (n << 1), cnt = 0; i < i_max; ++i) {
    if (a[i] == 1)
      ++cnt;
    else
      cnt = 0;
    max_end[i] = cnt;
  }
  for (int i = (n << 1) - 1, cnt = 0; i >= 0; --i) {
    if (a[i] == 1)
      ++cnt;
    else
      cnt = 0;
    max_start[i] = cnt;
  }
  vector<int> seg_tree((n << 4) | 1);
  build(seg_tree, a, 1, 0, (n << 1) - 1, max_end, max_start);
  string s;
  cin >> s;
  for (int i = 0, j = 0; i < q; ++i) {
    if (s[i] == '!')
    {
      ++j;
      j%=n;
    }
    else {
      cout << min(lcs(seg_tree, 1, 0, (n << 1) - 1, n-j, (n<<1)-j- 1, max_end,
                        max_start), k)
           << '\n';
    }
  }
  return 0;
}