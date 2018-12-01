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
  vector<int> fr(26, 0);
  int n;
  string s;
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; ++i) {
    fr[s[i] - 'a']++;
  }
  int cnt = 0;
  int mr = 0;
  for (int i = 0; i < 26; ++i) {
    if (fr[i] > 0) ++mr;
    if (fr[i] == 1) ++cnt;
  }
  if (cnt == mr && n > 1)
    cout << "No\n";
  else
    cout << "Yes\n";
  return 0;
}