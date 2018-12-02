#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);

int main() {
  FAST_IO
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> subject(m);
  for (int i = 0, s, r; i < n; ++i) {
    cin >> s >> r;
    subject[s - 1].push_back({r, 0});
  }
  vector<pair<int, int>> sorting(m);
  for (int i = 0; i < m; ++i) {
    sort(subject[i].rbegin(), subject[i].rend());
    for (int j = 0, sum = 0; j < subject[i].size(); ++j) {
      sum += subject[i][j].first;
      subject[i][j].second = sum;
    }
    sorting[i] = {subject[i].size(), i};
  }
  sort(sorting.rbegin(), sorting.rend());
  int max_skill = 0;
  int i = 0;
  while (i <= sorting[0].first) {
    int j = 0, skill = 0;
    while (j < m && i < sorting[j].first) {
      if (subject[sorting[j].second][i].second > 0)
        skill += subject[sorting[j].second][i].second;
      ++j;
    }
    max_skill = max(max_skill, skill);
    ++i;
  }
  cout << max_skill << endl;
  return 0;
}