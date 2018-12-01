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
  map<long long int, long long int> stage;
  long long int l, r;
  for (int i = 0; i < n; ++i) {
    cin >> l >> r;
    auto start = stage.find(l);
    if (start != stage.end())
      ++(start->second);
    else
      stage[l] = 1;

    auto end = stage.find(r + 1);
    if (end != stage.end())
      --(end->second);
    else
      stage[r + 1] = -1;
  }

  vector<long long int> count(n + 1, 0);
  int cnt = 0;
  for (auto i = stage.begin(), end = next(stage.end(), -1); i != end; ++i) {
    cnt += i->second;
    count[cnt] += next(i)->first - i->first;
  }
  for (int i = 1; i <= n; ++i) cout << count[i] << ' ';
  cout << '\n';
  return 0;
}