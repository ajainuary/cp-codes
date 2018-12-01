#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);
int sqrt_n;
bool block_divider(pair<pair<int, int>, int> &l, pair<pair<int, int>, int> &r) {
  auto left = l.first.first / sqrt_n;
  auto right = r.first.first / sqrt_n;
  if (left == right) return l.first.second < r.first.second;
  return left < right;
}

int main() {
  FAST_IO
  int n;
  cin >> n;
  sqrt_n = floor(sqrt(n));
  vector<int> a(n);
  for (int &x : a) cin >> x;
  int q;
  cin >> q;
  vector<pair<pair<int, int>, int>> queries(q);
  for (int i = 0; i < q; ++i) {
    cin >> queries[i].first.first >> queries[i].first.second;
    --queries[i].first.first;
    --queries[i].first.second;
    queries[i].second = i;
  }
  sort(queries.begin(), queries.end(), block_divider);
  vector<int> ans(q);
  vector<int> freq(1000006, 0);
  int answer = 0;
  int i = queries[0].first.first;
  int j = i - 1;
  for (auto &q : queries) {
    while (q.first.first < i) {
      --i;
      ++freq[a[i]];
      if (freq[a[i]] == 1) ++answer;
    }
    while (q.first.first > i) {
      --freq[a[i]];
      if (freq[a[i]] == 0) --answer;
      ++i;
    }
    while (q.first.second > j) {
      ++j;
      ++freq[a[j]];
      if (freq[a[j]] == 1) ++answer;
    }
    while (q.first.second < j) {
      --freq[a[j]];
      if (freq[a[j]] == 0) --answer;
      --j;
    }
    ans[q.second] = answer;
  }
  for (auto &x : ans) cout << x << '\n';
  return 0;
}