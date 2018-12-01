#include <bits/stdc++.h>
using namespace std;

int dsu_find(vector<int> &dsu, int i) {
  if (dsu[i] < 0) return i;
  dsu[i] = dsu_find(dsu, dsu[i]);
  return dsu[i];
}

void dsu_union(vector<int> &dsu, int i, int j) {
  int parent_i = dsu_find(dsu, i);
  int parent_j = dsu_find(dsu, j);
  if (parent_i == parent_j) return;
  if (dsu[parent_i] < dsu[parent_j])
    dsu[parent_j] = parent_i;
  else if (dsu[parent_j] < dsu[parent_i])
    dsu[parent_i] = parent_j;
  else {
    dsu[parent_i] = parent_j;
    --dsu[parent_j];
  }
  return;
}

bool syn(vector<int> &antonym, vector<int> &dsu, int i, int j) {
  if (antonym[dsu_find(dsu, i)] != -1 &&
      dsu_find(dsu, antonym[dsu_find(dsu, i)]) == dsu_find(dsu, j))
    return false;  // j is already an antonym of i
  if (antonym[dsu_find(dsu, j)] != -1 &&
      dsu_find(dsu, antonym[dsu_find(dsu, j)]) == dsu_find(dsu, i))
    return false;  // i is already an antonym of j
  int anti_i = antonym[dsu_find(dsu, i)], anti_j = antonym[dsu_find(dsu, j)];
  dsu_union(dsu, i, j);
  if (anti_i == -1 && anti_j == -1)
    antonym[dsu_find(dsu, i)] = -1;
  else if (anti_i == -1)
    antonym[dsu_find(dsu, i)] = anti_j;
  else if (anti_j == -1)
    antonym[dsu_find(dsu, i)] = anti_i;
  else {
    dsu_union(dsu, anti_i, anti_j);
    antonym[dsu_find(dsu, i)] = dsu_find(dsu, anti_i);
  }
  return true;
}

bool anti(vector<int> &antonym, vector<int> &dsu, int i, int j) {
  if (dsu_find(dsu, i) == dsu_find(dsu, j))
    return false;  // they are already synonyms
  if (antonym[dsu_find(dsu, i)] != -1 &&
      !syn(antonym, dsu, antonym[dsu_find(dsu, i)], j))
    return false;
  if (antonym[dsu_find(dsu, j)] != -1 &&
      !syn(antonym, dsu, antonym[dsu_find(dsu, j)], i))
    return false;
  if (antonym[dsu_find(dsu, i)] == -1)
    antonym[dsu_find(dsu, i)] = dsu_find(dsu, j);
  if (antonym[dsu_find(dsu, j)] == -1)
    antonym[dsu_find(dsu, j)] = dsu_find(dsu, i);

  return true;
}

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  map<string, int> wnum;
  string s;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    wnum[s] = i;
  }
  vector<int> antonym(n, -1);
  vector<int> dsu(n, -1);
  string p;
  for (int i = 0, t; i < m; ++i) {
    cin >> t >> s >> p;
    if (t == 1) {
      if (syn(antonym, dsu, wnum[s], wnum[p]))
        cout << "YES\n";
      else
        cout << "NO\n";
    } else {
      if (anti(antonym, dsu, wnum[s], wnum[p]))
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  for (int i = 0; i < q; ++i) {
    cin >> s >> p;
    int num_s = wnum[s];
    int num_p = wnum[p];
    if (dsu_find(dsu, num_s) == dsu_find(dsu, num_p))
      cout << "1\n";
    else if (antonym[dsu_find(dsu, num_s)] != -1 &&
             dsu_find(dsu, antonym[dsu_find(dsu, num_s)]) ==
                 dsu_find(dsu, num_p))
      cout << "2\n";
    else if (antonym[dsu_find(dsu, num_p)] != -1 &&
             dsu_find(dsu, antonym[dsu_find(dsu, num_p)]) ==
                 dsu_find(dsu, num_s))
      cout << "2\n";
    else
      cout << "3\n";
  }
  return 0;
}