#include <bits/stdc++.h>
using namespace std;

int dist(int i, int j, string &s1, string &s2, vector<vector<int>> &cache,
         int n2, int n1) {
  if (i < 0 || j < 0) {
    if (i < 0 && j < 0)
      return (n1 == n2) ? 0 : (n1 + n2);
    else if (i < 0)
      return j + 1;
    else if (j < 0)
      return i + 1;
  }
  if (cache[i][j] != -1) return cache[i][j];
  if (s1[i] != s2[j]) {
    cache[i][j] = min(min(dist(i - 1, j - 1, s1, s2, cache, n2, n1),
                          dist(i - 1, j, s1, s2, cache, n2 + 1, n1)),
                      dist(i, j - 1, s1, s2, cache, n2 - 1, n1)) +
                  1;
  } else
    cache[i][j] = dist(i - 1, j - 1, s1, s2, cache, n2, n1);
  return cache[i][j];
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n1, n2;
    cin >> n1 >> n2;
    vector<vector<int>> cache(n1, vector<int>(n2, -1));
    string s1, s2;
    cin >> s1;
    cin >> s2;
    cout << dist(n1 - 1, n2 - 1, s1, s2, cache, n2, n1) << '\n';
  }
  return 0;
}