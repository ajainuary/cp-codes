#include <bits/stdc++.h>
using namespace std;

int LCS(string &s1, string &s2, int i, int j, vector<vector<int>> &cache) {
  if (i < 0 || j < 0) return 0;
  if (cache[i][j] != -1) return cache[i][j];
  if (s1[i] != s2[j])
    cache[i][j] =
        max(LCS(s1, s2, i - 1, j, cache), LCS(s1, s2, i, j - 1, cache));
  else
    cache[i][j] = LCS(s1, s2, i - 1, j - 1, cache) + 1;
  return cache[i][j];
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n1, n2;
    cin >> n1 >> n2;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    vector<vector<int>> cache(n1, vector<int>(n2, -1));
    cout << LCS(s1, s2, n1 - 1, n2 - 1, cache) << '\n';
  }
  return 0;
}