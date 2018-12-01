#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, w, h;
  cin >> n >> w >> h;
  vector<pair<pair<int, int>, int>> envelope(n);
  for (int i = 0; i < n; ++i) {
    cin >> envelope[i].first.first >> envelope[i].first.second;
    envelope[i].second = i;
  }
  sort(envelope.begin(), envelope.end());
  vector<pair<int, int>> L(n, {0, -1});
  int max_lis_end = 0;
  for (int i = 0; i < n; ++i) {
    if (envelope[i].first.first > w && envelope[i].first.second > h) {
      int max_index = i;
      for (int j = 0; j < i; ++j)
        if (L[j] > L[max_index] &&
            envelope[j].first.second < envelope[i].first.second &&
            envelope[j].first.first < envelope[i].first.first)
          max_index = j;
      L[i] = {L[max_index].first + 1, (max_index != i) ? max_index : -1};
      if (L[i].first > L[max_lis_end].first) max_lis_end = i;
    }
  }
  cout << L[max_lis_end].first << '\n';
  if (L[max_lis_end].first == 0) return 0;
  vector<int> chain;
  int prev = max_lis_end;
  while (prev != -1) {
    chain.push_back(prev);
    prev = L[prev].second;
  }
  for (int i = int(chain.size()) - 1; i >= 0; --i)
    cout << envelope[chain[i]].second + 1 << ' ';
  cout << '\n';
  return 0;
}