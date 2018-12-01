#include <bits/stdc++.h>
using namespace std;

int main() {
  int p, s;
  cin >> p >> s;
  vector<vector<pair<int, int>>> problems(p, vector<pair<int, int>>(s));
  vector<pair<int, int>> difficulty(p);
  for (int i = 0; i < p; ++i) {
    for (auto &y : problems[i]) cin >> y.first;
    for (auto &y : problems[i]) cin >> y.second;
    sort(problems[i].begin(), problems[i].end());
    int n = 0;
    for (int j = 0; j < s - 1; ++j)
      if (problems[i][j].second > problems[i][j + 1].second) ++n;
    difficulty[i] = {n, i};
  }
  sort(difficulty.begin(), difficulty.end());
  for (auto &x : difficulty) cout << x.second+1 << '\n';
  return 0;
}