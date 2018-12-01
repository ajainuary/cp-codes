#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define sz(a) ll(a.size())
#define dbg(x) \
  { cerr << #x << " = " << x << endl; }

int main() {
  FAST_IO
  int n;
  cin >> n;
  vector<string> old(n);
  vector<string> cur(n);
  vector<vector<int>> olds(3, vector<int>(4, 0));
  vector<vector<int>> curs(3, vector<int>(4, 0));

  for (auto &x : old) {
    cin >> x;
    if (x == "XXXS")
      ++olds[0][3];
    else if (x == "XXS")
      ++olds[0][2];
    else if (x == "XS")
      ++olds[0][1];
    else if (x == "S")
      ++olds[0][0];
    else if (x == "M")
      ++olds[1][0];
    else if (x == "L")
      ++olds[2][0];
    else if (x == "XL")
      ++olds[2][1];
    else if (x == "XXL")
      ++olds[2][2];
    else if (x == "XXXL")
      ++olds[2][3];
  }
  for (auto &x : cur) {
    cin >> x;
    if (x == "XXXS")
      ++curs[0][3];
    else if (x == "XXS")
      ++curs[0][2];
    else if (x == "XS")
      ++curs[0][1];
    else if (x == "S")
      ++curs[0][0];
    else if (x == "M")
      ++curs[1][0];
    else if (x == "L")
      ++curs[2][0];
    else if (x == "XL")
      ++curs[2][1];
    else if (x == "XXL")
      ++curs[2][2];
    else if (x == "XXXL")
      ++curs[2][3];
  }
  int change = 0;
  for (int i = 0; i < 4; ++i) change += abs(curs[0][i] - olds[0][i]);
  for (int i = 0; i < 4; ++i) change += abs(curs[2][i] - olds[2][i]);
  change += abs(curs[1][0] - olds[1][0]);
  cout << change / 2 << endl;
  return 0;
}